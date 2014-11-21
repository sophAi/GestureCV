/* ======================================================================
File Name     : ScreenTool.cpp
Creation Time : 20141031 13:37:48
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
#include "ScreenTool.h"
using namespace module_ScreenTool;

ScreenTool::ScreenTool() 
{

}

ScreenTool::~ScreenTool()
{

}

int ScreenTool::screenWidth()
{
		return screen_height;
}

int ScreenTool::screenHeight()
{
		return screen_width;
}

void ScreenTool::X11Screen()
{
		Display *disp = XOpenDisplay(NULL);
		Screen *xscrn = DefaultScreenOfDisplay(disp);
		screen_height = xscrn->height;
		screen_width = xscrn->width;
		
}
