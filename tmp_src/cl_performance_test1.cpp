/* ============================================================
File Name     : opencl_test.cpp
Creation Time : 20141020 08:16:15
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include <opencv2/core.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/highgui.hpp>
//#include <opencv2/contrib.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utility.hpp>
#include <iostream>
 
#define USE_OPENCL
 
int main(int argc, const char* argv[])
{
if(argc != 2)
{
std::cerr << "Usage : UMatVideoSample <input video file>" << std::endl;
return -1;
}
cv::VideoCapture reader(argv[1]);
if(!reader.isOpened())
{
std::cerr << "Can't open input video file: " << argv[1] << std::endl;
return -1;
}
 
cv::UMat frame;
cv::UMat gray;
cv::UMat blur;
cv::UMat edge;

int start_count, end_count;
double count_freq;
 
#ifdef USE_OPENCL
cv::ocl::setUseOpenCL(true);
#else
cv::ocl::setUseOpenCL(false);
#endif
count_freq = cv::getTickFrequency();
for(int i = 1;; ++i)
{
reader >> frame;
if(frame.empty())
{
std::cout << "Stop" << std::endl;
break;
}
 
start_count = cv::getTickCount();
cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
cv::GaussianBlur(gray, blur, cv::Size(1,1), 1.5, 1.5);
cv::Canny(blur, edge, 0, 30, 3);
end_count = cv::getTickCount();
std::cout << "[" << i << "] " << (double)(end_count-start_count)/count_freq << "(count)" << std::endl;
}
 
return 0;
}
