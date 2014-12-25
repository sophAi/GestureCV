/* ============================================================
File Name     : main.cpp
Creation Time : 20140722 15:34:05
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory.
=============================================================== */
#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <X11/Xlib.h>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "Distribution.hpp"
#include "Draw.hpp"
#include "VirtualInput"
//#include <opencv2/core/ocl.hpp>
//#include "cvocl.hpp"

int main( int argc, char **argv)
{
		Display *disp=XOpenDisplay(NULL);
        Screen *scrn = DefaultScreenOfDisplay(disp);
        int screen_height = scrn->height;
        int screen_width = scrn->width;
		enum KeyType {kRelease, kPressed};
		enum MoveType {kAbsolute, kRelative}; 
		int x, y;
        int trigger_type_a, 
			key1_a = KEY_LEFT, 
			key2_a = -1, 
			key3_a = -1,
			button_a = -1;
        int trigger_type_b, 
			key1_b = KEY_RIGHT, 
			key2_b = -1, 
			key3_b = -1,
			button_b = -1;
        int trigger_type_c, 
			key1_c = KEY_UP, 
			key2_c = -1, 
			key3_c = -1,
			button_c = -1;
        int trigger_type_d, 
			key1_d = KEY_DOWN, 
			key2_d = -1, 
			key3_d = -1,
			button_d = -1;

        module_CmdLine::CmdLine *pCmdLine = new module_CmdLine::CmdLine();

        pCmdLine->setup(argc, argv);

        module_VirtualInput::VirtualInput *pVirtualInput = new module_VirtualInput::VirtualInput();
		
		pVirtualInput->setup(screen_width, screen_height, (int)kRelative);

		float fps,frame_num=0;
		long total_hsv_time=0;  
		int x_mean,x_var, y_mean, y_var, frame_width,frame_height,x_pos,y_pos;
		int x_pre_pos,y_pre_pos,x_diff,y_diff,x_trigger_threshold,y_trigger_threshold;
		struct timeval init_time, end_time, hsv_init_time, hsv_end_time;
		float x_factor, y_factor;
		int camera_id = 0;
		float screen_x = 1920;
		float screen_y = 1080;
		float camera_x = 160;
		float camera_y = 120;
//		cv::ocl::setUseOpenCL(true); // enable OpenCL in the processing of UMat
		x_factor =(screen_x/camera_x);
		y_factor =(screen_y/camera_y);
		cv::Mat frame, edges, hsv, skinBinary, x_hist, y_hist, elem_erode(5, 5, CV_8U, cv::Scalar(1)),elem_dilate(5, 5, CV_8U, cv::Scalar(1));
		cv::VideoCapture cap(camera_id);
		cap.set(cv::CAP_PROP_FRAME_WIDTH, camera_x);
		cap.set(cv::CAP_PROP_FRAME_HEIGHT, camera_y);
		cap.set(cv::CAP_PROP_FPS, 15);
		cap.set(cv::CAP_PROP_BRIGHTNESS, 1); //0-1
		cap.set(cv::CAP_PROP_CONTRAST, 1);  //0-1
		std::cout << "get info=" << cap.get(cv::CAP_PROP_BRIGHTNESS) << std::endl;
		cap>>frame;
		frame_width=frame.cols;
		frame_height=frame.rows;
		std::cout << "Frame x=" << frame_width << ", frame y=" << frame_height <<std::endl;
		Distribution *pDist= new Distribution(frame_width,frame_height);
		Draw draw;
		if(!cap.isOpened())
				return -1;

		cv::namedWindow("edge",1);
		std::cout << "Press ESC to exit\n";
		gettimeofday(&init_time,0);
		x_diff=0;
		y_diff=0;
		x_pre_pos=screen_x/2;
		y_pre_pos=screen_y/2;
		x_trigger_threshold=250;
		y_trigger_threshold=170;
		for(;;) {
//				cv::namedWindow("edge",1);
				cap>>frame;

//=================HSV normal============
				cv::cvtColor(frame,edges,cv::COLOR_BGR2HSV);
			    cv::inRange(edges,cv::Scalar(0,58,20), cv::Scalar(70,173,255),frame);  //This is for the skin tone of HSV
//			    cv::inRange(edges,cv::Scalar(0,58,20), cv::Scalar(50,255,255),frame);  //This is for the skin tone of HSV
// ===============YCrCb=================
//				cv::cvtColor(frame,edges,cv::COLOR_BGR2YCrCb);
//			    cv::inRange(edges,cv::Scalar(75,130,0), cv::Scalar(135,180,255),frame);    //This is for the skin tone of YCrCb
//			    cv::inRange(edges,cv::Scalar(75,130,0), cv::Scalar(200,180,255),frame);    //This is for the skin tone of YCrCb
				cv::GaussianBlur(frame,edges,cv::Size(7,7),5,5);
//				cv::Canny(edges,frame,20,50,3);
//			    cv::fastNlMeansDenoising(edges, frame);
//			    cv::Erode()
//				cv::Dilate()
//			    cv::morphologyEx(edges, frame, cv::MORPH_CLOSE, elem);
//			    cv::morphologyEx(frame, edges, cv::MORPH_OPEN, elem);
//			    cv::morphologyEx(frame, edges, cv::MORPH_CLOSE, elem);
			    cv::dilate(edges, frame,elem_dilate);
			    cv::erode(frame, edges,elem_erode);
			    pDist->Distribution_2D(edges,x_hist, y_hist, x_mean, x_var, y_mean, y_var);
				cv::imshow("edges",edges);
			    draw.showHistogram(x_hist,y_hist,x_pos,y_pos);    
			    x_pos = 1920 - (float) x_pos * x_factor;
			    y_pos = (float) y_pos * y_factor;
//			    std::cout << "x_pos=" << x_pos << ",y_pos=" << y_pos << std::endl;
//			    UserInput::move(x_pos,y_pos);

			    if (y_diff < -y_trigger_threshold) {
						UserInput::keyPress(KEY_PAGEUP);
						std::cout << "Detect Page Up" << std::endl;
			    }
				if (y_diff > y_trigger_threshold) {
						UserInput::keyPress(KEY_PAGEDOWN);
						std::cout << "Detect Page Down" << std::endl;
				}
				if (x_diff < -x_trigger_threshold) {
						UserInput::keyPress(KEY_LEFT);
						std::cout << "Detect Left" << std::endl;
				}
				if (x_diff > x_trigger_threshold) {
						UserInput::keyPress(KEY_RIGHT);
						std::cout << "Detect Right" << std::endl;
				}
			    y_diff=y_pos-y_pre_pos;
				x_diff=x_pos-x_pre_pos;
//			    std::cout << "x_diff= " << x_diff << ", y_diff= " << y_diff << std::endl;
			    x_pre_pos=x_pos;
				y_pre_pos=y_pos;

			    gettimeofday(&hsv_end_time,0);
			    total_hsv_time += (hsv_end_time.tv_usec+hsv_end_time.tv_sec*1000000-hsv_init_time.tv_usec-hsv_init_time.tv_sec*1000000);
			    frame_num += 1;
			    if (frame_num == 100) {
					    gettimeofday(&end_time,0);
				        fps = 1000000*frame_num/(end_time.tv_usec+end_time.tv_sec*1000000-init_time.tv_usec-init_time.tv_sec*1000000);
				        std::cout << "fps=" << fps << " hsv_time/frame= " << total_hsv_time/1000000 <<"\n";
						frame_num = 0;
						total_hsv_time=0;
						gettimeofday(&init_time,0);
				}

				if((char)cv::waitKey(30) == 27) break;
		}
		frame.release();

		delete pDist;

		delete pVirtualInput;

		delete pCmdLine;

		exit(0);
}


