#ifndef _Draw_H_
#define _Draw_H_

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class Draw
{
public:
		Draw() {};
		virtual ~Draw() {};
		void showHistogram(const cv::Mat &horizontal, 
						   const cv::Mat &vertical,
						   int &x_pos,
						   int &y_pos);
};

#endif
