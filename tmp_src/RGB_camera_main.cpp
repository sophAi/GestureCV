/* ============================================================
File Name     : main.cpp
Creation Time : 20141015 15:14:24
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include "CmdLine.h"
#include "CvRGBCamera.h"
#include "Distribution.h"
#include "VirtualInput.h"

int main(int argc, char **argv)
{
		int camera_x = 160;
		int camera_y = 120;
		int camera_fps = 15;
		int camera_brightness = 1;
		int camera_contrast = 1;

        int threshold_key_x = camera_x*64/1280;
        int threshold_key_y = camera_y*40/720;
        int threshold_move_x = camera_x*16/1280;
        int threshold_move_y = camera_y*12/720;


		module_CmdLine::CmdLine *pCmdLine = new module_CmdLine::CmdLine();
		pCmdLine->setup(argc, argv);

		module_CvRGBCamera::CvRGBCamera *pCvRGBCamera = new module_CvRGBCamera::CvRGBCamera(0);

		module_Distribution::Distribution *pDistribution = new module_Distribution::Distribution(camera_x, camera_y);


		if (pCvRGBCamera->setup(camera_x, camera_y, camera_fps, camera_brightness, camera_contrast) == 1) {
			std::cerr << "Error!" << std::endl;
		}

		pCvRGBCamera->setupOpenGLWindow("frame");
/*
		pCvRGBCamera->setupOpenGLWindow("hist_x");
		pCvRGBCamera->setupOpenGLWindow("pos_x");

		pCvRGBCamera->setupOpenGLWindow("hist_y");
		pCvRGBCamera->setupOpenGLWindow("pos_y");
*/
		int lower1 = 0;
		int upper1 = 50;
		int lower2 = 50;
		int upper2 = 173;
		int lower3 = 20;
		int upper3 = 230;

		int pos_x, pos_y, pos_pre_x = 0, pos_pre_y = 0, diff_x = 0, diff_y = 0;
		cv::Mat dist_x = cv::Mat::zeros(1, camera_x, CV_32SC1);
		cv::Mat dist_y = cv::Mat::zeros(camera_y, 1, CV_32SC1);

		int count = 0, count_threshold = camera_fps;
		while (cv::waitKey(30) != 27) {
				pDistribution->imageDist2d(pCvRGBCamera->HSVBinary(lower1, lower2, lower3, upper1, upper2, upper3), (int *)dist_x.data, (int *)dist_y.data);
				pos_x = pDistribution->imageDistMean((int *)dist_x.data, 0, camera_x);
				pos_y = pDistribution->imageDistMean((int *)dist_y.data, 0, camera_y);
				pCvRGBCamera->showBinary("frame",0, camera_x, 0, camera_y);
//				pCvRGBCamera->showHistogram("hist_x", (int *)dist_x.data, 0, camera_x);
//				pCvRGBCamera->showHistogram("hist_y", (int *)dist_y.data, 0, camera_y);
//				pCvRGBCamera->showLine("pos_x",pos_x,0 , camera_x);
//				pCvRGBCamera->showLine("pos_y",pos_y,0 , camera_y);
//				std::cout << "pos_x=" << pos_x << ",diff_x=" << diff_x << ",pos_y=" << pos_y << ",diff_y=" << diff_y << std::endl;
//				printf("%d %d %d %d\n", camera_x, camera_y, pos_x, pos_y);

				if (count > 0) {
						count--;
//						std::cout << "count= " << count <<std::endl;
				} else { 

						if (diff_y < -threshold_key_y) {
								diff_x = pos_pre_x - pos_x;
								diff_y = pos_y - pos_pre_y;
								pos_pre_x = pos_x;
								pos_pre_y = pos_y;
								printf("%d %d %d %d %d %d %d %d\n", 1, KEY_LEFTALT, KEY_X, -1, -1, 0, 0, 1);
		                        fflush(stdout);
				                usleep(25000);
						        printf("%d %d %d %d %d %d %d %d\n", 0, KEY_LEFTALT, KEY_X, -1, -1, 0, 0, 1);
								fflush(stdout);
								count = count_threshold;
				                continue;
						}

		                if (diff_y > threshold_key_y) {
								diff_x = pos_pre_x - pos_x;
								diff_y = pos_y - pos_pre_y;
								pos_pre_x = pos_x;
								pos_pre_y = pos_y;
				                printf("%d %d %d %d %d %d %d %d\n", 1, -1, -1, -1, BTN_LEFT, 0, 0, 1);
						        fflush(stdout);
								usleep(25000);
		                        printf("%d %d %d %d %d %d %d %d\n", 0, -1, -1, -1, BTN_LEFT, 0, 0, 1);
				                fflush(stdout);
								count = count_threshold;
								continue;
		                }

		                if (diff_x < -threshold_key_x) {
								diff_x = pos_pre_x - pos_x;
								diff_y = pos_y - pos_pre_y;
								pos_pre_x = pos_x;
								pos_pre_y = pos_y;
				                printf("%d %d %d %d %d %d %d %d\n", 1, KEY_LEFT, -1, -1, -1, 0, 0, 1);
						        fflush(stdout);
								usleep(25000);
		                        printf("%d %d %d %d %d %d %d %d\n", 0, KEY_LEFT, -1, -1, -1, 0, 0, 1);
				                fflush(stdout);
								count = count_threshold;
								continue;
		                }

		                if (diff_x > threshold_key_x) {
								diff_x = pos_pre_x - pos_x;
								diff_y = pos_y - pos_pre_y;
								pos_pre_x = pos_x;
								pos_pre_y = pos_y;
				                printf("%d %d %d %d %d %d %d %d\n", 1, KEY_RIGHT, -1, -1, -1, 0, 0, 1);
						        fflush(stdout);
								usleep(25000);
		                        printf("%d %d %d %d %d %d %d %d\n", 0, KEY_RIGHT, -1, -1, -1, 0, 0, 1);
				                fflush(stdout);
								count = count_threshold;
								continue;
		                }

						if (abs(diff_y) > threshold_move_y && abs(diff_x) > threshold_move_x) {
								diff_x = pos_pre_x - pos_x;
								diff_y = pos_y - pos_pre_y;
								pos_pre_x = pos_x;
								pos_pre_y = pos_y;
		                        printf("%d %d %d %d %d %d %d %d\n", 1, -1, -1, -1, -1, diff_x*10, diff_y*10, 1);
				                fflush(stdout);
								count = count_threshold;
								continue;
		                } else if (abs(diff_y) > threshold_move_y) {
								diff_x = pos_pre_x - pos_x;
								diff_y = pos_y - pos_pre_y;
								pos_pre_x = pos_x;
								pos_pre_y = pos_y;
				                printf("%d %d %d %d %d %d %d %d\n", 1, -1, -1, -1, -1, 0, diff_y*10, 1);
		                        fflush(stdout);
								count = count_threshold;
		                        continue;
		                } else if (abs(diff_x) > threshold_move_x) {
								diff_x = pos_pre_x - pos_x;
								diff_y = pos_y - pos_pre_y;
								pos_pre_x = pos_x;
								pos_pre_y = pos_y;
		                        printf("%d %d %d %d %d %d %d %d\n", 1, -1, -1, -1, -1, diff_x*10, 0, 1);
		                        fflush(stdout);
								count = count_threshold;
		                        continue;
		                }
				}
//				printf("%d %d %d %d %d %d %d %d\n", 0, -1, -1, -1, -1, 0, 0, 1);
				diff_x = pos_pre_x - pos_x;
				diff_y = pos_y - pos_pre_y;
				pos_pre_x = pos_x;
				pos_pre_y = pos_y;
		}

		delete pDistribution;

		delete pCvRGBCamera;

		delete pCmdLine;


		exit(0);
}

