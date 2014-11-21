/* ======================================================================
File Name     : receive_uinput.cpp
Creation Time : 20141015 15:14:24
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
#include <iostream>
#include <stdio.h>
#include "CmdLine.h"
#include "VirtualInput.h"
#include "ScreenTool.h"

int main(int argc, char **argv)
{
		module_CmdLine::CmdLine *pCmdLine = new module_CmdLine::CmdLine();
		pCmdLine->setup(argc, argv);

		module_ScreenTool::ScreenTool *pScreenTool = new module_ScreenTool::ScreenTool();
		pScreenTool->X11Screen();
		int screen_width = pScreenTool->screenWidth();
		int screen_height = pScreenTool->screenHeight();

		int move_type_switch = -1; //0 for absolute, 1 for relative
		int trigger_type, key1, key2, key3, button, x, y, move_type;
		module_VirtualInput::VirtualInput *pVirtualInput = new module_VirtualInput::VirtualInput();

		while(scanf("%d %d %d %d %d %d %d %d\n",
                &trigger_type,
                &key1,
                &key2,
                &key3,
                &button,
                &x,
                &y,
                &move_type) != EOF) {
				fflush(stdin);
				printf("%d %d %d %d %d %d %d %d\n", trigger_type, key1, key2, key3, button, x, y, move_type);
				fflush(stdout);
				if (move_type_switch != move_type) {
						pVirtualInput->setup(screen_width, screen_height, move_type);
						move_type_switch = move_type;
				}
				pVirtualInput->control(trigger_type, key1, key2, key3, button, x, y);

	    }

		delete pScreenTool;

		delete pVirtualInput;

		delete pCmdLine;

		exit(0);
}

