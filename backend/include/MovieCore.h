#pragma once
#include <list>
#include <opencv2/opencv.hpp>


namespace mv::core
{
	void setMask(cv::Mat &img);
	void cutImg(cv::Mat &img, const cv::Point &tlc, const cv::Size &sz);
	bool findTemplate(const cv::Mat &img, const cv::Mat &templ, const double &threshold);


	std::string framePosToHMS(const int &pos);
	std::list<std::pair<int, int>> readSourceVideo(const int &s_pos, const int &e_pos, const int &thread_num, const int &entrance_num);
	std::pair<int, int> getKillSegment(const std::pair<int, int> &segm, const std::pair<int, int> &range, const int &step);

	
	void correctList(std::list<std::pair<int, int>> &list);
	void toFileFormat(const std::list<std::pair<int, int>> &list, const std::string &txt = "cuts.txt");
}
