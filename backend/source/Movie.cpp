#include <filesystem>
#include <vector>
#include <list>

#include "MovieExceptions.h"
#include "Controller.h"
#include "MovieCore.h"
#include "Movie.h"


namespace mv::data
{
	static constexpr int max_threads = 9;


	Data::Data()
	{
		template_pos  = { 1600, 0  };
		search_area   = { 240, 270 };

		time_to_kill       = 6;
		time_after_kill    = 0;
		time_between_kills = 5;

		frame_step = 50;
		threshold  = 0.8;

		threads_count = 3;
	}

	void Data::dataIsValid() noexcept(false)
	{
        std::filesystem::path path;

        path = input_video_path;
        if (!std::filesystem::exists(path)) {
            throw exc::cantFindInputVideo;
        }
        path = output_video_dir;
        if (!std::filesystem::is_directory(path)) {
            throw exc::cantFindOutputDir;
        }
        path = template_img_path;
        if (!std::filesystem::exists(path)) {
            throw exc::cantFindTemplImg;
        }
			
        cv::VideoCapture reader(input_video_path);
        if (!reader.isOpened()) {
            throw exc::cantOpenInputVideo;
        }

        const int
            frames_count = reader.get(cv::CAP_PROP_FRAME_COUNT),
            frame_width  = reader.get(cv::CAP_PROP_FRAME_WIDTH),
            frame_height = reader.get(cv::CAP_PROP_FRAME_HEIGHT);

        cv::Mat templ = cv::imread(template_img_path);
        cv::Size max_area = { frame_width - template_pos.x, frames_count - template_pos.y };


        if (template_pos.x >= frame_width || template_pos.x < 0) {
            throw exc::invalidPointPosX;
        }
        if (template_pos.y >= frame_height || template_pos.y < 0) {
            throw exc::invalidPointPosY;
        }
        if (search_area.width > max_area.width || search_area.height > max_area.height) {
            throw exc::bigSearchArea;
        }
        if (search_area.width < templ.cols || search_area.height < templ.rows) {
            throw exc::lessSearchArea;
        }
        if (frame_step >= frames_count) {
            throw exc::bigStep;
        }
        if (threshold <= 0 || threshold >= 1) {
            throw exc::invalidThreshold;
        }
        if (threads_count <= 0 || threads_count > max_threads) {
            throw exc::invalidThreadsCount;
        }
	}
}

namespace mv
{
	Movie* Movie::singleton = nullptr;

	Movie::Movie() 
	{
		connect(this, &Movie::sendLog, ctrl::Controller::getInstanse(), &ctrl::Controller::catchLog, Qt::DirectConnection);		// "inline" call
		connect(this, &Movie::endLog, ctrl::Controller::getInstanse(), &ctrl::Controller::frize, Qt::QueuedConnection);			// target GUI queue
	}

	Movie::Movie(const data::Data &data):
		Movie() 
	{
		user_data = data;
	}

	Movie::Movie(data::Data &&data):
		Movie()
	{
		user_data = std::move(data);
	}

	Movie* Movie::getInstanse() noexcept 
	{
		if (!singleton) {
			singleton = new Movie;
		}
		return singleton;
	}

	Movie* Movie::getInstanse(const data::Data &data) noexcept 
	{
		if (!singleton) {
			singleton = new Movie(data);
		}
		return singleton;
	}


	data::Data* Movie::getInstanceData() noexcept {
		return new data::Data(getInstanse()->user_data);
	}

	data::Data* Movie::getData() noexcept {
		return new data::Data(getInstanse()->user_data);
	}

	void Movie::updateData(data::Data &&data) noexcept {
		user_data = std::move(data);
	}

	void Movie::updateData(const data::Data &data) noexcept {
		user_data = data;
	}

	
	// Start Backend
	void Movie::createMovie() 
	{
		static int entrance = 1;
		
		cv::VideoCapture reader(user_data.input_video_path);
		if (!reader.isOpened()) {
			throw exc::cantOpenInputVideo;
		}

		const int frames_count = reader.get(cv::CAP_PROP_FRAME_COUNT);
		const int threads_count = user_data.threads_count;
		const int delt_fr = std::max(1, frames_count / threads_count);
		int start_pos = 0;

		std::vector<std::thread> threads;
		std::vector<std::list<std::pair<int, int>>> results;
		results.resize(threads_count);                                                  // Logs how comments
                                                                                        emit sendLog("Preparing streams...");

		for (int i = 0; i < threads_count; ++i) {

			int end_pos = (i + 1 == threads_count) ? frames_count : start_pos + delt_fr;
			threads.push_back(std::thread(
				[=, &results]() { 
					results[i] = std::move(core::readSourceVideo(start_pos, end_pos, i, entrance)); 
				}
			));                                                                         emit sendLog("Added stream (" + std::to_string(i + 1) + ")\tvideo range: \t" 
																						    + core::framePosToHMS(start_pos) + " - " + core::framePosToHMS(end_pos));
			start_pos = end_pos;
		}                                                                               emit sendLog("\n\n\n\t  ...please, wait___(-o_o-)___ wait, please...\n\n");
		for (auto &th: threads) th.join();                                              emit sendLog("\n\t\tAll streams ended!\n");


		std::list<std::pair<int, int>> mergelist;
		for (auto &list: results) {
			if (!list.empty()) {
				mergelist.splice(mergelist.end(), list);
			}
		}

		if (mergelist.empty()) {                                                        emit sendLog("You didn't kill anyone in this video!\nMay be your settings are wrong...");
			++entrance;                                                                 emit endLog();
			return;
		}

		core::correctList(mergelist);                                                   emit sendLog("\nCorrect kills segments:");
                                                                                        for (const auto &i: mergelist) emit sendLog("Time range:\t\t" + core::framePosToHMS(i.first) + " - " + core::framePosToHMS(i.second));																	
                                                                                        emit sendLog("\nFormating...");
		core::toFileFormat(mergelist);                                                  emit sendLog("Writing movie...");

		constexpr auto ffmpeg_cmd = "ffmpeg -f concat -safe 0 -i cuts.txt -c copy ";
		std::string command = ffmpeg_cmd + ("\"" + user_data.output_video_dir + '/' 
			+ user_data.output_video_name + user_data.output_video_format + "\"");
		int res = system(command.c_str());                                              emit sendLog(res == 0 ? "Mission complete...\n" : "Failed to record video! Input video path must not contain non-Latin letters or '\n");
															       
		++entrance;                                                                     emit endLog();
	}
}