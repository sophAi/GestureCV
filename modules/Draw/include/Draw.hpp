/* ============================================================
File Name     : Draw.h
Creation Time : 20141218 10:51:50
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#ifndef sophAi_modules_Draw_H_
#define sophAi_modules_Draw_H_

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
