/* ============================================================
File Name     : opencl_test2.cpp
Creation Time : 20141022 11:32:22
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include "opencv2/opencv.hpp"
#include "opencv2/core/ocl.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

  ocl::setUseOpenCL(true);
  Mat gpuFrame;
  UMat gpuBW;
  UMat gpuBlur;
  UMat gpuEdges;
  VideoCapture cap(0); // open the default camera
  if(!cap.isOpened())  // check if we succeeded
    return -1;
  namedWindow("edges",1);
  for(;;)
    {
      cap >> gpuFrame; // get a new frame from camera
      cvtColor(gpuFrame, gpuBW, COLOR_BGR2GRAY);
      GaussianBlur(gpuBW, gpuBlur, Size(1,1), 1.5, 1.5);
      Canny(gpuBlur, gpuEdges, 0, 30, 3);
      imshow("edges", gpuEdges);
      if(waitKey(30) >= 0) break;
    }
  // the camera will be deinitialized automatically in VideoCapture destructor
  return 0;
}
