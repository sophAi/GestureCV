/* ============================================================
File Name     : CvRGBCamera.cpp
Creation Time : 20141103 16:18:00
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include "CvRGBCamera.h"
using namespace module_CvRGBCamera;

CvRGBCamera::CvRGBCamera(int select_camera_id)
{
		camera_id = select_camera_id;
}

CvRGBCamera::~CvRGBCamera()
{
		if (this->capture != NULL)
				this->capture->release();
				delete this->capture;
}

int CvRGBCamera::setup(int width,
					   int height,
					   int fps,
					   float brightness,
					   float contrast)
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


void CvRGBCamera::showROITrackbar(const std::string &window_name,
								  int &ROI_x_lower,
								  int &ROI_x_upper,
								  int &ROI_y_lower,
								  int &ROI_y_upper,
								  int &ROI_sum_threshold)
{
		cv::createTrackbar("ROI x lower", window_name, &ROI_x_lower, 160, NULL);
		cv::createTrackbar("ROI x upper", window_name, &ROI_x_upper, 160, NULL);
		cv::createTrackbar("ROi y lower", window_name, &ROI_y_lower, 120, NULL);
		cv::createTrackbar("ROI y upper", window_name, &ROI_y_upper, 120, NULL);
		cv::createTrackbar("ROI sum threshold", window_name, &ROI_sum_threshold, 19200, NULL);
}

void CvRGBCamera::showThresholdTrackbar(const std::string &window_name,
										int &threshold_key_x_left,
										int &threshold_key_x_right,
										int &threshold_key_y_up,
										int &threshold_key_y_down,
										int &count_threshold_short,
										int &count_threshold_long)
{
		cv::createTrackbar("Left threshold", window_name, &threshold_key_x_left, 30, NULL);
		cv::createTrackbar("Right threshold", window_name, &threshold_key_x_right, 30, NULL);
		cv::createTrackbar("Up threshold", window_name, &threshold_key_y_up, 30, NULL);
		cv::createTrackbar("Down threshold", window_name, &threshold_key_y_down, 30, NULL);
		cv::createTrackbar("Short threshold", window_name, &count_threshold_short, 30, NULL);
		cv::createTrackbar("Long threshold", window_name, &count_threshold_long, 30, NULL);
}


void CvRGBCamera::showHSVTrackbar(const std::string &window_name, 
								  int &lower1,
								  int &lower2,
								  int &lower3,
								  int &upper1,
								  int &upper2,
								  int &upper3)
{
		cv::createTrackbar("Hue lower", window_name, &lower1, 179, NULL);
		cv::createTrackbar("Hue upper", window_name, &upper1, 179, NULL);
		cv::createTrackbar("Sat lower", window_name, &lower2, 255, NULL);
		cv::createTrackbar("Sat upper", window_name, &upper2, 255, NULL);
		cv::createTrackbar("Val lower", window_name, &lower3, 255, NULL);
		cv::createTrackbar("Val upper", window_name, &upper3, 255, NULL);
}

void CvRGBCamera::showRGB(const std::string &window_name)
{
		this->capture->read(frame);
		cv::imshow(window_name, frame);
}

void CvRGBCamera::showHSV(const std::string &window_name)
{
		this->capture->read(frame);
		cv::cvtColor(frame, frame, cv::COLOR_BGR2HSV);
		cv::imshow(window_name, frame);
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
//		cv::GaussianBlur(binary, binary, cv::Size(7, 7), 5, 5);
//		cv::dilate(binary, binary, elem_dilate);
//		cv::erode(binary, binary, elem_erode);
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
