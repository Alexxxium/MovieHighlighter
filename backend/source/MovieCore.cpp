#include <QApplication>
#include <QScreen>
#include <memory>
#include <fstream>
#include <filesystem>

#include "Movie.h"
#include "MovieCore.h"
#include "Controller.h"
#include "MovieExceptions.h"
#include "WaiteQueue/WaiteQueue.h"

#pragma warning(disable: 26479)


namespace mv::core
{
	void show(const cv::Mat &img, const int &thread_num, const int &entrance_num = 1)
	{
		constexpr int margin = 250, rows = 3, cols = 3;

		static QList<QScreen*> screens = QGuiApplication::screens();
		static const auto &mtrx = screens.first()->size();

		const int
			user_w = mtrx.width(),
			user_h = mtrx.height(),
			img_w = (user_w - 2 * margin) / rows,
			img_h = (user_h - 2 * margin) / cols;

		const auto &pos = [&]() -> cv::Point {
			return { margin + img_w * (thread_num % cols) , margin + img_h * (thread_num / rows) };
		};

		cv::Mat copy;
		cv::Point sz = std::move(pos());
		cv::resize(img, copy, { img_w, img_h });
		std::string
			thread_str = "Thread " + std::to_string(thread_num + 1),
			entrance_str = " (" + std::to_string(entrance_num) + ')';

		cv::imshow(thread_str + entrance_str, copy);
		cv::moveWindow(thread_str + entrance_str, sz.x, sz.y);
	}

	void cutImg(cv::Mat &img, const cv::Point &tlc, const cv::Size &sz) {
		if (img.empty()) {
			throw exc::emptyImage;
		}

		cv::Rect rect(tlc, sz);
		img = img(rect);
	}

	void setMask(cv::Mat &img) {
		if (img.empty()) {
			throw exc::emptyImage;
		}

		cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
		cv::threshold(img, img, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

		std::vector<std::vector<cv::Point>> contours;
		cv::findContours(img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

		img = cv::Mat(img.size(), CV_8UC3, cv::Scalar(255, 255, 255));
		cv::drawContours(img, contours, -1, cv::Scalar(0, 0, 0), cv::FILLED);
	}

	bool findTemplate(const cv::Mat &img, const cv::Mat &templ, const double &threshold) {
		if (img.empty()) {
			throw exc::emptyImage;
		}
		if (templ.empty()) {
			throw exc::emptyTemplate;
		}
		if (threshold <= 0 || threshold >= 1) {
			throw exc::invalidThreshold;
		}

		cv::Mat res;
		cv::matchTemplate(img, templ, res, cv::TM_CCOEFF_NORMED);

		double min_val, max_val;
		cv::Point min_loc, max_loc;
		cv::minMaxLoc(res, &min_val, &max_val, &min_loc, &max_loc);

		return max_val >= threshold;
	}



	std::string framePosToHMS(const int &pos) {
		std::unique_ptr<data::Data> data(Movie::getInstanceData());
		const cv::VideoCapture video(data->input_video_path);

		if (!video.isOpened()) {
			throw exc::cantOpenVideo;
		}

		constexpr int
			hours_den = 3600,
			minutes_den = 60,
			max_num = 10,
			max_len = 6;

		const int fps = video.get(cv::CAP_PROP_FPS);
		double seconds = (double) pos / fps;

		int hrs, mnts;
		std::string scnds, res;

		hrs = seconds / hours_den;
		seconds -= hrs * hours_den;

		mnts = seconds / minutes_den;
		seconds -= mnts * minutes_den;

		res += (hrs < max_num) ? ('0' + std::to_string(hrs) + ':') : std::to_string(hrs) + ':';
		res += (mnts < max_num) ? ('0' + std::to_string(mnts) + ':') : std::to_string(mnts) + ':';
		scnds = (seconds < max_num) ? ('0' + std::to_string(seconds)) : std::to_string(seconds);

		if (scnds.size() > max_len) {
			scnds.resize(max_len);
		}

		res += scnds;

		return std::move(res);
	}

	// O(2 * log(step))
	std::pair<int, int> getKillSegment(const std::pair<int, int> &segm, const std::pair<int, int> &range, const int &step) 
	{
		if (segm.first > segm.second) {
			throw exc::invalidSegm;
		}
		if (step > range.second - range.first) {
			throw exc::bigStep;
		}
		if (segm.first < range.first || segm.second > range.second) {
			throw exc::outOfRange;
		}

		std::unique_ptr<data::Data> data(Movie::getInstanceData());
		cv::VideoCapture video(data->input_video_path);

		if (!video.isOpened()) {
			throw exc::cantOpenVideo;
		}

		cv::Mat frame, templ = cv::imread(data->template_img_path);
		setMask(templ);

		int l = std::max(range.first, segm.first - step);
		int r = segm.first;
		int mid = (r + l) / 2;
		std::pair<int, int> res;

		while (l < r) {
			video.set(cv::CAP_PROP_POS_FRAMES, mid);
			video >> frame;
			cutImg(frame, data->template_pos, data->search_area);
			setMask(frame);

			if (findTemplate(frame, templ, data->threshold)) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}

			mid = (r + l) / 2;
		}
		res.first = mid;

		l = segm.second;
		r = std::min(segm.second + step, range.second);
		mid = (l + r) / 2;

		while (l < r) {
			video.set(cv::CAP_PROP_POS_FRAMES, mid);
			video >> frame;
			cutImg(frame, data->template_pos, data->search_area);
			setMask(frame);

			if (findTemplate(frame, templ, data->threshold)) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}

			mid = (r + l) / 2;
		}
		res.second = mid;

		return std::move(res);
	}

	std::list<std::pair<int, int>> core::readSourceVideo(const int &s_pos, const int &e_pos, const int &thread_num, const int &entrance_num) 
	{
		std::unique_ptr<data::Data> data(Movie::getInstanceData());
		cv::VideoCapture reader(data->input_video_path);
		auto movie = Movie::getInstanse();


		if (!reader.isOpened()) {
			throw exc::cantOpenVideo;
		}

		const int frames_count = reader.get(cv::CAP_PROP_FRAME_COUNT);

		if (s_pos < 0 || s_pos > e_pos || e_pos > frames_count) {
			throw exc::invalidPos;
		}


		cv::Mat frame;
		cv::Mat templ = cv::imread(data->template_img_path);
		setMask(templ);
		
		int curr_pos = s_pos;
		const int step = data->frame_step;
		constexpr std::pair<int, int> dflt_segm = { -1, -1 };

		algs::WaiteQueue queue;
		std::list<std::pair<int, int>> kills;
		std::pair<int, int> segm = dflt_segm;
		
		std::string winname = "Search area (" + std::to_string(entrance_num) + ')';

		while (curr_pos < e_pos) {
			reader.set(cv::CAP_PROP_POS_FRAMES, curr_pos);
			reader >> frame;

			bool showMode = SHOW_MODE();

			if (showMode) {
				show(frame, thread_num, entrance_num); 
			}
			
			cutImg(frame, data->template_pos, data->search_area);
			setMask(frame);

			if (findTemplate(frame, templ, data->threshold)) {
				if (segm.first == -1) {
					segm.first = curr_pos;
				}
				else if (segm.second == -1 && curr_pos - segm.first <= step) {
					segm.second = curr_pos;
				}
				else if (curr_pos - segm.second <= step) {
					segm.second = curr_pos;
				}
				else {
					segm.second = segm.second == -1 ? segm.first : segm.second;
					queue.push(
						[=, &kills]() {
							kills.push_back(std::move(getKillSegment(segm, {s_pos, e_pos}, step)));
							const auto &ref = kills.back();
emit movie->sendLog("stream (" + std::to_string(thread_num + 1) + ")\tfound kill segment:\t" + core::framePosToHMS(ref.first) + " - " + core::framePosToHMS(ref.second));
						}
					);
					segm = dflt_segm;
					segm.first = curr_pos;
				}

			}

			curr_pos += step;

			if (showMode) {
				cv::namedWindow(winname, cv::WINDOW_NORMAL);
				cv::imshow(winname, frame);
				cv::moveWindow(winname, 0, 0);
				if (cv::waitKey(1) == 27) {
					break;
				}
			}
		}
		if (segm != dflt_segm) {
			segm.second = segm.second == -1 ? segm.first : segm.second;
			queue.push(
				[=, &kills]() {
					kills.push_back(std::move(getKillSegment(segm, { s_pos, e_pos }, step)));
					const auto &ref = kills.back();
emit movie->sendLog("stream (" + std::to_string(thread_num + 1) + ")\tfound kill segment:\t" + core::framePosToHMS(ref.first) + " - " + core::framePosToHMS(ref.second));
				}
			);
		}
		queue.waite();

		return std::move(kills);
	}



	void correctList(std::list<std::pair<int, int>> &list) {
		if (list.empty()) {
			throw exc::emptyList;
		}

		std::unique_ptr<data::Data> data(Movie::getInstanceData());
		cv::VideoCapture video(data->input_video_path);

		if (!video.isOpened()) {
			throw exc::cantOpenInputVideo;
		}

		const int 
			len = video.get(cv::CAP_PROP_FRAME_COUNT),
			fps = video.get(cv::CAP_PROP_FPS),
			ttk = data->time_to_kill * fps,
			tak = data->time_after_kill * fps,
			tbk = data->time_between_kills * fps;

		auto prev = list.begin();
		auto it = std::next(prev);
		const auto &end = list.end();

		while (it != end) {
			if (it->first - prev->second <= tbk) {
				prev->second = it->second;
				it = list.erase(it);
				continue;
			}

			prev->first = std::max(0, prev->first - ttk);
			prev->second = std::min(len, prev->second + tak);
			++prev;
			++it;
		}

		auto config = list.rbegin();
		config->first = std::max(0, prev->first - ttk);
		config->second = std::min(len, prev->second + tak);
	}

	void toFileFormat(const std::list<std::pair<int, int>> &list, const std::string &txt) {
		std::ofstream file(txt);
		std::unique_ptr<data::Data> data(Movie::getInstanceData());
		
		constexpr auto
			inpoint = "inpoint ",
			outpoint = "outpoint ",
			file_cmd = "file \'";

		std::string put_file = data->input_video_path;

		for (const auto &i : list) {
			file <<
				file_cmd << put_file << "\'\n" <<
				inpoint  << framePosToHMS(i.first)  << '\n' <<
				outpoint << framePosToHMS(i.second) << '\n' << std::endl;
		}
	}
}