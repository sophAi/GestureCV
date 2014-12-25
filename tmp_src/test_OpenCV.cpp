/* ============================================================
File Name     : main.cpp
Creation Time : 20140722 15:34:05
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory.
=============================================================== */
//#define CVOCL
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
//#include "cvocl.hpp"
#include <sys/time.h>
#include <unistd.h>
#include "VirtualInput.h"
#include "Distribution.h"
#include "Draw.hpp"
//#include <opencv2/core/ocl.hpp>

int main( int argc, const char **argv)
{
		float fps,frame_num=0;
		long total_hsv_time=0;  
		int x_mean,x_var, y_mean, y_var, frame_width,frame_height,x_pos,y_pos;
		int x_pre_pos,y_pre_pos,x_diff,y_diff,x_trigger_threshold,y_trigger_threshold;
		struct timeval init_time, end_time, hsv_init_time, hsv_end_time;
		float x_factor, y_factor;
		int camera_id = 0;
		int screen_x = 1920;
		int screen_y = 1080;
		int camera_x = 640;
		int camera_y = 480;
//		cv::ocl::setUseOpenCL(true); // enable OpenCL in the processing of UMat
		x_factor =((float)screen_x/(float)camera_x);
		y_factor =((float)screen_y/(float)camera_y);
		cv::Mat frame, edges, hsv, skinBinary, elem_erode(5, 5, CV_8U, cv::Scalar(1)),elem_dilate(5, 5, CV_8U, cv::Scalar(1));
		cv::Mat buffer_frame;
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
		module_Distribution::Distribution *pDist= new module_Distribution::Distribution(camera_x, camera_y);
		Draw draw;
		if(!cap.isOpened())
				return -1;

//		cv::namedWindow("edge",1);
		std::cout << "Press ESC to exit\n";
		gettimeofday(&init_time,0);
		x_diff=0;
		y_diff=0;
		x_pre_pos=(float)screen_x/2;
		y_pre_pos=(float)screen_y/2;
		x_trigger_threshold=camera_x*40/1280;
		y_trigger_threshold=camera_y*50/720;

		module_VirtualInput::VirtualInput *pVirtualInput = new module_VirtualInput::VirtualInput();

		int move_type = 0;
		pVirtualInput->setup(screen_x, screen_y, move_type);
		int trigger_type = -1, button ,dummy_key = -1;
		int no_move = -1;
		int left = KEY_LEFT;
		int right = KEY_RIGHT;
		int up = KEY_UP;
		int down = KEY_DOWN;
		int alt = KEY_LEFTALT;
		int x = KEY_X;
		int click =BTN_TOUCH;
		int x_max = 0, x_min = screen_x, y_max = 0, y_min = screen_y;
		int x_move, y_move;
		int count_threshold = 20;
		int count = count_threshold;

		cap.read(frame);
		cv::cvtColor(frame,buffer_frame,cv::COLOR_BGR2HSV);
		cv::inRange(buffer_frame,cv::Scalar(10,20,100), cv::Scalar(30,80,255),buffer_frame);  //This is for the skin tone of HSV
		unsigned char *input_array, *x_dist_array, *y_dist_array;
        cv::Mat x_dist = cv::Mat::zeros(1, camera_x, CV_32SC1);
        cv::Mat y_dist = cv::Mat::zeros(camera_y, 1, CV_32SC1);
		cv::namedWindow("edges",cv::WINDOW_AUTOSIZE);
		for(;;) {
//				cap>>frame;
				cap.read(frame);
//				std::cout<<frame <<std::endl;
//=================HSV normal============
				cv::cvtColor(frame,edges,cv::COLOR_BGR2HSV);
				cv::inRange(edges,cv::Scalar(0,58,20), cv::Scalar(80,173,255),edges);  //This is for the skin tone of HSV
//				frame = edges - buffer_frame;
//				buffer_frame = edges;
//				cv::inRange(edges,cv::Scalar(0,58,20), cv::Scalar(50,255,255),frame);  //This is for the skin tone of HSV
// ===============YCrCb=================
//				cv::cvtColor(frame,edges,cv::COLOR_BGR2YCrCb);
//				cv::inRange(edges,cv::Scalar(75,130,0), cv::Scalar(135,180,255),frame);    //This is for the skin tone of YCrCb
//				cv::inRange(edges,cv::Scalar(75,130,0), cv::Scalar(200,180,255),frame);    //This is for the skin tone of YCrCb
				cv::GaussianBlur(edges,edges,cv::Size(7,7),5,5);
//				cv::Canny(edges,frame,20,50,3);
//				cv::fastNlMeansDenoising(edges, frame);
//				cv::Erode()
//				cv::Dilate()
//				cv::morphologyEx(edges, frame, cv::MORPH_CLOSE, elem);
//				cv::morphologyEx(frame, edges, cv::MORPH_OPEN, elem);
//				cv::morphologyEx(frame, edges, cv::MORPH_CLOSE, elem);
				cv::dilate(edges, edges,elem_dilate);
				cv::erode(edges, edges,elem_erode);

				pDist->imageDist2d(edges.data, (int *)x_dist.data, (int *)y_dist.data);

//				x_pos = pDist->imageDistMean((int *)x_dist.data, 0, camera_x);
				
//				y_pos = pDist->imageDistMean((int *)y_dist.data, 0, camera_y);
//				pDist->Distribution_2D(edges.data,x_dist, y_dist, x_mean, x_var, y_mean, y_var);


				cv::imshow("edges",edges);
				draw.showHistogram(x_dist,y_dist,x_pos,y_pos);    
//				x_pos = 1920 - (float) x_pos * x_factor;
//				y_pos = (float) y_pos * y_factor;
//				std::cout << "x_pos=" << x_pos << ",y_pos=" << y_pos << std::endl;
	
//				UserInput::move(x_diff,y_diff);
				if(x_pos > x_max) x_max = x_pos;
				if(x_pos < x_min) x_min = x_pos;
				if(y_pos > y_max) y_max = y_pos;
				if(y_pos < y_min) y_min = y_pos;
//				std::cout << "x_min=" << x_min << ",x_max=" << x_max << std::endl;
//				std::cout << "y_min=" << y_min << ",y_max=" << y_max << std::endl;
//				std::cout << "x_pos=" << x_pos << ",y_pos=" << y_pos << std::endl;

				if(abs(y_diff) > y_trigger_threshold || abs(x_diff) > x_trigger_threshold) {
						if (y_diff < -y_trigger_threshold) {
								trigger_type = 1;	
								pVirtualInput->control(trigger_type, alt, x, dummy_key, dummy_key, no_move, no_move);
								usleep(50);
								trigger_type = 0;
								pVirtualInput->control(trigger_type, alt, x, dummy_key, dummy_key, no_move, no_move);
								std::cout << "Detect Page Up" << std::endl;
						}

						if (y_diff > y_trigger_threshold) {
								trigger_type = 1;	
								pVirtualInput->control(trigger_type, dummy_key, dummy_key, dummy_key, click, no_move, no_move);
								usleep(50);
								trigger_type = 0;
								pVirtualInput->control(trigger_type, dummy_key, dummy_key, dummy_key, click, no_move, no_move);
								std::cout << "Detect Page Down" << std::endl;
						}

						if (x_diff < -x_trigger_threshold) {
								trigger_type = 1;	
								pVirtualInput->control(trigger_type, left, dummy_key, dummy_key, dummy_key, no_move, no_move);
								usleep(50);
								trigger_type = 0;
								pVirtualInput->control(trigger_type, left, dummy_key, dummy_key, dummy_key, no_move, no_move);
								std::cout << "Detect Left" << std::endl;
						}

						if (x_diff > x_trigger_threshold) {
								trigger_type = 1;	
								pVirtualInput->control(trigger_type, right, dummy_key, dummy_key, dummy_key, no_move, no_move);
								usleep(50);
								trigger_type = 0;
								pVirtualInput->control(trigger_type, right, dummy_key, dummy_key, dummy_key, no_move, no_move);
								std::cout << "Detect Right" << std::endl;
						}

/*				} else {

						if(abs(x_diff) > 10 && abs(x_diff) < x_trigger_threshold) {
								x_move = 1920-((float)(x_pos-x_min)*((float)screen_x/(float)(x_max-x_min)));
								pVirtualInput->control(trigger_type, dummy_key, dummy_key, dummy_key, dummy_key, x_move, no_move);
						}

						if(abs(y_diff) > 10 && abs(y_diff) < y_trigger_threshold) {
								y_move = (float)(y_pos-y_min)*((float)screen_y/(float)(y_max-y_min));
								pVirtualInput->control(trigger_type, dummy_key, dummy_key, dummy_key, dummy_key, no_move, y_move);
						}
*/				}

				y_diff=y_pos-y_pre_pos;
				x_diff=x_pre_pos-x_pos;
//				std::cout << "x_diff= " << x_diff << ", y_diff= " << y_diff << std::endl;
				x_pre_pos=x_pos;
				y_pre_pos=y_pos;
				gettimeofday(&hsv_end_time,0);
				total_hsv_time += (hsv_end_time.tv_usec+hsv_end_time.tv_sec*1000000-hsv_init_time.tv_usec-hsv_init_time.tv_sec*1000000);
				frame_num += 1;
 
				if (frame_num == 100) {
						gettimeofday(&end_time,0);
						fps = 1000000*frame_num/(end_time.tv_usec+end_time.tv_sec*1000000-init_time.tv_usec-init_time.tv_sec*1000000);
//						std::cout << "fps=" << fps << " hsv_time/frame= " << total_hsv_time/1000000 <<"\n";
						frame_num = 0;
						total_hsv_time=0;
						gettimeofday(&init_time,0);
				}

				if((char)cv::waitKey(30) == 27) break;
		}
		frame.release();
		delete pDist;
		delete pVirtualInput;
		return 0;
}


