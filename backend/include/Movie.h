#pragma once
#include <opencv2/opencv.hpp>
#include <QObject>


namespace mv::data
{
	struct Data
	{
	public:

		std::string
			input_video_path,
			output_video_dir,
			output_video_name,
			output_video_format,
			template_img_path;

		cv::Point template_pos;
		cv::Size search_area;

		double
			time_to_kill,
			time_after_kill,
			time_between_kills;

		int frame_step;
		double threshold;

		int threads_count;

		void dataIsValid() noexcept(false);

	
//Semantic:
		Data();

		Data(Data&&) = default;
		Data(const Data&) = default;

		Data& operator=(Data&&) = default;
		Data& operator=(const Data&) = default;

		~Data() = default;
	};
}

namespace mv
{
	class Movie: public QObject
	{
		Q_OBJECT

	private:

		static Movie *singleton;
		data::Data user_data;
		
		Movie();
		explicit Movie(data::Data&& data);
		explicit Movie(const data::Data &data);
		
		Movie(Movie&&) = delete;
		Movie(const Movie&) = delete;

	public:

		static Movie* getInstanse() noexcept;
		static Movie* getInstanse(const data::Data &data) noexcept;
		static data::Data* getInstanceData() noexcept;

		data::Data* getData() noexcept;

		void updateData(data::Data &&data) noexcept;
		void updateData(const data::Data &data) noexcept;

		void createMovie();


	signals:

		void sendLog(const std::string &log);
		void endLog(bool val = true);
	};
}
