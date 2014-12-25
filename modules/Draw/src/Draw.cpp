/* ============================================================
File Name     : Draw.cpp
Creation Time : 20140929 14:46:51
Last Modified : 20140930 17:41:25
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory.
=============================================================== */
#include "Draw.hpp"
#include <iostream>

void Draw::showHistogram(const cv::Mat &xDistribution, const cv::Mat &yDistribution,int &x_pos, int &y_pos)
{
		int upper_boundary =100;
		int lower_boundary =0;
		cv::Mat xDistributionNorm, yDistributionNorm;
		cv::Mat xHist = cv::Mat::zeros(upper_boundary, xDistribution.cols, CV_8UC1);
		cv::Mat yHist = cv::Mat::zeros(yDistribution.rows, upper_boundary, CV_8UC1);
		cv::normalize(xDistribution, xDistributionNorm, lower_boundary, upper_boundary, cv::NORM_MINMAX, CV_8UC1);
		cv::normalize(yDistribution, yDistributionNorm, lower_boundary, upper_boundary, cv::NORM_MINMAX, CV_8UC1);

        //xHist.cols=640
		//yHist.rows=480	
	
		int xMean = 0,yMean = 0;
		int xTotal = 0, yTotal = 0;
        int lower_xROI=0,upper_xROI=xHist.cols, lower_yROI=0, upper_yROI=yHist.rows;
//		std::cout << "xTotal=" << xTotal << std::endl;
//		std::cout << "yTotal=" << yTotal << std::endl;
		
		for (int x_id = lower_xROI; x_id < upper_xROI; ++x_id)
		{

				uint32_t xValue = (uint32_t)xDistributionNorm.at<uchar>(x_id);
				xMean = xMean + x_id * xValue;
                xTotal = xTotal + xValue;
				cv::Rect rect(x_id, 0, 1, xValue);
				cv::rectangle(xHist, rect, 255, -1);
		}

		for (int y_id = lower_yROI; y_id < upper_yROI; ++y_id)
		{

				uint32_t yValue = (uint32_t)yDistributionNorm.at<uchar>(y_id);
				yMean = yMean + y_id * yValue;
				yTotal = yTotal + yValue;
				cv::Rect rect(upper_boundary - yValue, y_id, yValue, 1);
				cv::rectangle(yHist, rect, 255, -1);
		}
//		std::cout << "xPos=" << xMean/xTotal[0] << std::endl;
        x_pos = xMean/xTotal;
		y_pos = yMean/yTotal;
		cv::Rect rect1(x_pos, 0, 2, upper_boundary);
		cv::rectangle(xHist, rect1, upper_boundary, -1);
		cv::Rect rect2(0,(y_pos),upper_boundary, 2);
		cv::rectangle(yHist, rect2, upper_boundary, -1);
//		yMean = yMean / (uint32_t)yTotal;
		cv::imshow("xHist", xHist);
		cv::imshow("yHist", yHist);
}

