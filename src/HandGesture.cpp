/* ======================================================================
File Name     : HandGesture.cpp
Creation Time : 20141015 15:14:24
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
#include "CmdLine.h"
#include "CvRGBCamera.h"
#include "Distribution.h"
#include "VirtualInput.h"
#include "ScreenTool.h"
#include "XMLTool.h"

int main(int argc, char **argv)
{
		int camera_x = 640;
		int camera_y = 480;
		int camera_fps = 15;
		int camera_brightness = 1;
		int camera_contrast = 1;

		int cut_x_lower = 0; // 35;
		int cut_x_upper = 0; // 35;
		int cut_y_lower = 0; // 50;
		int cut_y_upper = 0; // 20;
		int ROI_x_lower = cut_x_lower*(camera_x/160);
		int ROI_x_upper = camera_x - cut_x_upper*(camera_x/160);
		int ROI_y_lower = cut_y_lower*(camera_y/120);
		int ROI_y_upper = camera_y - cut_y_upper*(camera_y/120);
		int ROI_x_length = ROI_x_upper - ROI_x_lower + 1;
		int ROI_y_length = ROI_y_upper - ROI_y_lower + 1;
		int ROI_sum_threshold = 800;

        int threshold_key_x_left = 7;//6;
		int threshold_key_x_right = 7;
        int threshold_key_y_up = 7;//5;
		int threshold_key_y_down = 7 ;
        int threshold_move_x = 6;// 2;
        int threshold_move_y = 6;// 2;

		threshold_key_x_left = threshold_key_x_left * (camera_x/160);
		threshold_key_x_right = threshold_key_x_right * (camera_x/160);
		threshold_key_y_up = threshold_key_y_up * (camera_y/120);
		threshold_key_y_down = threshold_key_y_down * (camera_y/120);
		threshold_move_x = threshold_move_x * (camera_x/160);
		threshold_move_y = threshold_move_y * (camera_y/120);

		module_CmdLine::CmdLine *pCmdLine = new module_CmdLine::CmdLine();
		pCmdLine->setup(argc, argv);

		module_CvRGBCamera::CvRGBCamera *pCvRGBCamera = new module_CvRGBCamera::CvRGBCamera(0);

		module_Distribution::Distribution *pDistribution = new module_Distribution::Distribution(camera_x, camera_y);

		pDistribution->imageROI(ROI_x_lower, ROI_x_upper, ROI_y_lower, ROI_y_upper);

		module_VirtualInput::VirtualInput *pVirtualInput = new module_VirtualInput::VirtualInput();

		module_ScreenTool::ScreenTool *pScreenTool = new module_ScreenTool::ScreenTool();
		pScreenTool->X11Screen();
		int screen_x = pScreenTool->screenWidth();
		int screen_y = pScreenTool->screenHeight();
		int move_type = 1;
		pVirtualInput->setup(screen_x, screen_y, move_type);
		sleep(1);


		if (pCvRGBCamera->setup(camera_x, camera_y, camera_fps, camera_brightness, camera_contrast) == 1) {
			std::cerr << "Error!" << std::endl;
		}

		pCvRGBCamera->setupAutosizeWindow("frame");

//		pCvRGBCamera->setupOpenGLWindow("hist_x");
//		pCvRGBCamera->setupOpenGLWindow("pos_x");

//		pCvRGBCamera->setupOpenGLWindow("hist_y");
//		pCvRGBCamera->setupOpenGLWindow("pos_y");

//		int lower1 = 0;
//		int upper1 = 50;
//		int lower2 = 50;
//		int upper2 = 173;
//		int lower3 = 20; //20
//		int upper3 = 230;//230;

		int lower1 = 10;  //H_upper H/2; 0-180
		int upper1 = 30;  //H_upper 
		int lower2 = 20;    //S_lower   S*255;  0-255
		int upper2 = 80;  //S_upper    
		int lower3 = 100;    //V_lower   V*255;  0-255
		int upper3 = 255;  //V_upper

		int pos_x, pos_y, pos_pre_x = 0, pos_pre_y = 0, diff_x = 0, diff_y = 0;
		cv::Mat dist_x = cv::Mat::zeros(1, camera_x, CV_32SC1);
		cv::Mat dist_y = cv::Mat::zeros(camera_y, 1, CV_32SC1);

		int count_threshold_short = 4, count_threshold_long = 10;
		int left_count = 0, right_count = 0, up_count = 0, down_count = 0;

		int no_move = -1;
		int press = 1, release = 0;

		int dx, dy;
		int move_factor = 2;
//		int move_step = 5;

		module_XMLTool::XMLTool *pXMLTool = new module_XMLTool::XMLTool();
		std::string dat_path = "dat/";

		std::string XML_file_name = dat_path;
	
		XML_file_name.append("0.xml");

		std::vector<std::vector<int> > key_array(5, std::vector<int> (4) );

		if(pXMLTool->setupVirtualInputKeyMap(XML_file_name.c_str(), key_array) != 0) {
				std::cerr << "Error! Cannot initial kep map" << std::endl;
				exit(-1);
		}

		int read_key = -1;

		char return_key[32];

		Display *display;

		while (read_key != 27) {
				read_key = cv::waitKey(15);

//				XQueryKeymap(display, return_key);
//				std::cout << "return_key = " << return_key << std::endl;
				pDistribution->imageDist2d(pCvRGBCamera->HSVBinary(lower1, lower2, lower3, upper1, upper2, upper3), (int *)dist_x.data, (int *)dist_y.data);
				pos_x = pDistribution->imageDistMean((int *)dist_x.data, 0, ROI_x_length, ROI_sum_threshold);
				pos_y = pDistribution->imageDistMean((int *)dist_y.data, 0, ROI_y_length, ROI_sum_threshold);
				pCvRGBCamera->showBinary("frame", ROI_x_lower, ROI_x_upper, ROI_y_lower, ROI_y_upper);
//				pCvRGBCamera->showHistogram("hist_x", (int *)dist_x.data, 0, ROI_x_length);
//				pCvRGBCamera->showHistogram("hist_y", (int *)dist_y.data, 0, ROI_y_length);
//				pCvRGBCamera->showLine("pos_x",pos_x, ROI_x_lower, ROI_x_upper);
//				pCvRGBCamera->showLine("pos_y",pos_y, ROI_y_lower, ROI_y_upper);
//				std::cerr << "pos_x=" << pos_x << ",diff_x=" << diff_x << ",pos_y=" << pos_y << ",diff_y=" << diff_y << std::endl;
				if (read_key > 47 && read_key < 58) {  //"0" == 48, "1" == 49, ... , "9" == 57
						XML_file_name = dat_path;
						XML_file_name.append(std::to_string(read_key-48)).append(".xml");
						if(pXMLTool->setupVirtualInputKeyMap(XML_file_name.c_str(), key_array) == 0) {
								pVirtualInput->setup(screen_x, screen_y, key_array[0][1]);
								std::cout << "Loading " << XML_file_name << std::endl;
						} else {
								std::cerr << "Error! Cannot find " << XML_file_name << std::endl;
						}
						read_key = -1;
				}

				if (left_count > 0) {
						left_count--;
				}
				if (right_count > 0) {
						right_count--;
				}
				if (up_count > 0) {
						up_count--;
				}
				if (down_count > 0) {
						down_count--;
				} 

				if (pos_x > -1 && pos_y > -1) {
						if (key_array[0][0] > 0) {
								dx = diff_x * move_factor;
								dy = diff_y * move_factor;
						} else {
								dx = no_move;
								dy = no_move;
						}

						if (diff_x < -threshold_key_x_left && left_count == 0) {

								std::cout << "Detect Left!!" << std::endl;
								pVirtualInput->control(press, key_array[1][0], key_array[2][0], key_array[3][0], key_array[4][0], dx, no_move);
								if (key_array[0][0] == 0) {
										usleep(100);
										pVirtualInput->control(release, key_array[1][0], key_array[2][0], key_array[3][0], key_array[4][0], no_move, no_move);
										up_count = count_threshold_long;
										down_count = count_threshold_long;
								}
								left_count = count_threshold_short;
								right_count = count_threshold_long;
	
						}

						if (diff_x > threshold_key_x_right && right_count == 0) {
							
								std::cout << "Detect Right!!" << std::endl;
								pVirtualInput->control(press, key_array[1][1], key_array[2][1], key_array[3][1], key_array[4][1], dx, no_move);
								if (key_array[0][0] == 0) {
										usleep(100);
										pVirtualInput->control(release, key_array[1][1], key_array[2][1], key_array[3][1], key_array[4][1], no_move, no_move);
										up_count = count_threshold_long;
										down_count = count_threshold_long;
								}	
								left_count = count_threshold_long;
								right_count = count_threshold_short;
						}
		
						if (diff_y < -threshold_key_y_up && up_count == 0) {

								std::cout << "Detect Up!!" << std::endl;
								pVirtualInput->control(press, key_array[1][2], key_array[2][2], key_array[3][2], key_array[4][2], no_move, dy);
								if (key_array[0][0] == 0) {
										usleep(100);
										pVirtualInput->control(release, key_array[1][2], key_array[2][2], key_array[3][2], key_array[4][2], no_move, no_move);
										right_count = count_threshold_long;
										left_count = count_threshold_long;
								}
								up_count = count_threshold_short;
								down_count = count_threshold_long;
						}

						if (diff_y > threshold_key_y_down && down_count == 0) {
		
								std::cout << "Detect Down!!" << std::endl;
								pVirtualInput->control(press, key_array[1][3], key_array[2][3], key_array[3][3], key_array[4][3], no_move, dy);
								if (key_array[0][0] == 0) {
										usleep(100);
										pVirtualInput->control(release, key_array[1][3], key_array[2][3], key_array[3][3], key_array[4][3], no_move, no_move);
										right_count = count_threshold_long;
										left_count = count_threshold_long;
								}
								up_count = count_threshold_long;
								down_count = count_threshold_short;	
						}

						diff_x = pos_pre_x - pos_x;
						diff_y = pos_y - pos_pre_y;
						pos_pre_x = pos_x;
						pos_pre_y = pos_y;
//						printf("%d %d %d %d %d %d %d %d\n", 0, -1, -1, -1, -1, 0, 0, 1);
				}
		}

		delete pXMLTool;
		
		delete pScreenTool;

		delete pVirtualInput;

		delete pDistribution;

		delete pCvRGBCamera;

		delete pCmdLine;


		exit(0);
}

