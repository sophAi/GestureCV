/* ======================================================================
File Name     : CvRGBCamera.cpp
Creation Time : 20141103 16:18:00
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
#include "CvRGBCamera.h"
using namespace module_CvRGBCamera;

CvRGBCamera::CvRGBCamera(int select_camera_id)
{
		camera_id = select_camera_id;
}

int CvRGBCamera::setup(int width,
					   int height,
					   int fps,
					   int brightness,
					   int contrast)
{
	    this->capture = new cv::VideoCapture(this->camera_id);

/*		if (this->capture->isOpened() == false)
		{
				if (this->capture != NULL)
						delete this->capture;
						
				return 1;
		}
*/
		this->capture->set(cv::CAP_PROP_FRAME_WIDTH, width);
		this->capture->set(cv::CAP_PROP_FRAME_HEIGHT, height);
		this->capture->set(cv::CAP_PROP_FPS, fps);
		this->capture->set(cv::CAP_PROP_BRIGHTNESS, brightness);
		this->capture->set(cv::CAP_PROP_CONTRAST, contrast);
		cv::Mat elem_erode(5, 5, CV_8U, cv::Scalar(1));
        cv::Mat elem_dilate(5, 5, CV_8U, cv::Scalar(1));
        return 0;
}

void CvRGBCamera::setupOpenGLWindow(const std::string &window_name)
{
		cv::namedWindow(window_name, cv::WINDOW_OPENGL);
}

void CvRGBCamera::setupAutosizeWindow(const std::string &window_name)
{
		cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
}

void CvRGBCamera::setupNormalWindow(const std::string &window_name)
{
		cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
}

uchar *CvRGBCamera::HSVBinary(int &lower1,
							  int &lower2,
							  int &lower3,
							  int &upper1,
							  int &upper2,
							  int &upper3)
{
		this->capture->read(frame);
		cv::cvtColor(frame,binary,cv::COLOR_BGR2HSV);
		cv::inRange(binary, cv::Scalar(lower1, lower2, lower3), cv::Scalar(upper1, upper2, upper3), binary);
		cv::GaussianBlur(binary, binary, cv::Size(7, 7), 5, 5);
		cv::dilate(binary, binary, elem_dilate);
		cv::erode(binary, binary, elem_erode);
		return binary.data;
}

void CvRGBCamera::showBinary(const std::string &window_name, int ROI_x_lower, int ROI_x_upper, int ROI_y_lower, int ROI_y_upper)
{
		cv::Rect rect(ROI_x_lower, ROI_y_lower, ROI_x_upper-ROI_x_lower, ROI_y_upper-ROI_y_lower);
		cv::rectangle(binary, rect, 100, 1);
		cv::imshow(window_name, binary);
}

void CvRGBCamera::showHistogram(const std::string &window_name, int *input_array, int lower_id, int upper_id)
{
		int length = upper_id-lower_id+1;
		cv::Mat hist = cv::Mat::zeros(255, length, CV_8UC1);
		
		for (int i = 0; i < length; ++i) {
				
				cv::Rect rect(i, 0, 1, *(input_array+lower_id+i));
				cv::rectangle(hist, rect, 255, -1);
		}
		cv::imshow(window_name,hist);
}

void CvRGBCamera::showLine(const std::string &window_name, int &pos, int lower_id, int upper_id)
{
		cv::Mat line = cv::Mat::zeros(255,upper_id-lower_id, CV_8UC1);

		cv::Rect rect(pos, 0, 2, 255);
		cv::rectangle(line, rect, 255, -1);
		cv::imshow(window_name,line);
}

CvRGBCamera::~CvRGBCamera()
{
		if (this->capture != NULL)
				this->capture->release();
				delete this->capture;

}
