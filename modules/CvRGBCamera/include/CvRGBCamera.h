/* ============================================================
File Name     : CvRGBCamera.h
Creation Time : 20141103 15:55:44
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#ifndef sophAi_modules_CvRGBCamera_H_
#define sophAi_modules_CvRGBCamera_H_

#include <unistd.h>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/ocl.hpp"

namespace module_CvRGBCamera {
class CvRGBCamera
{
	public:

		CvRGBCamera(int select_camera_id);

		~CvRGBCamera();

		int setup(int width,
				  int height,
				  int fps,
				  float brightness,
				  float contrast);

		void setupOpenGLWindow(const std::string &window_name);

		void setupAutosizeWindow(const std::string &window_name);

		void setupNormalWindow(const std::string &window_name);

		void showROITrackbar(const std::string &window_name,
                             int &ROI_x_lower,
                             int &ROI_x_upper,
                             int &ROI_y_lower,
                             int &ROI_y_upper,
							 int &ROI_sum_threshold);
	
		void showThresholdTrackbar(const std::string &window_name,
							   	   int &threshold_key_x_left,
								   int &threshold_key_x_right,
								   int &threshold_key_y_up,
								   int &threshold_key_y_down,
								   int &count_threshold_short,
								   int &count_threshold_long);

		void showHSVTrackbar(const std::string &window_name,
							 int &lower1,
							 int &lower2,
							 int &lower3,
							 int &upper1,
							 int &upper2,
							 int &upper3);


		unsigned char *HSVBinary(int &lower1,
								 int &lower2,
								 int &lower3,
								 int &upper1,
								 int &upper2,
								 int &upper3);

		void showRGB(const std::string &window_name);

		void showHSV(const std::string &window_name);

		void showBinary(const std::string &window_name, 
						int ROI_x_lower, 
						int ROI_x_upper, 
						int ROI_y_lower, 
						int ROI_y_upper);
	
		void showHistogram(const std::string &window_name, 
						   int *input_array, 
						   int lower_id, 
						   int upper_id);

		void showLine(const std::string &window_name, 
					  int &pos, 
					  int lower_id, 
					  int upper_id);
	
	private:

		int camera_id;
		cv::Mat frame, binary, hist, line;
		cv::Mat elem_erode;
		cv::Mat elem_dilate;
		cv::VideoCapture *capture;
};
}
#endif

