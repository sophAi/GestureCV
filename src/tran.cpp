/* ============================================================
File Name     : receive_uinput.cpp
Creation Time : 20141015 15:14:24
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include <iostream>
#include <stdio.h>
#include "CmdLine.h"
#include "VirtualInput.h"
#include "ScreenTool.h"

int main(int argc, char **argv)
{
		module_CmdLine::CmdLine *pCmdLine = new module_CmdLine::CmdLine();
		pCmdLine->setup(argc, argv);

//		module_ScreenTool::ScreenTool *pScreenTool = new module_ScreenTool::ScreenTool();
//		pScreenTool->X11Screen();
//		int screen_width = pScreenTool->screenWidth();
//		int screen_height = pScreenTool->screenHeight();
//		int I0, press = 1, release = 0, no_move = -1;
//		int move_type_switch = -1; //0 for absolute, 1 for relative
		int trigger_time_us, key1, key2, key3, button, x, y, move_type, step, move_factor;
//		module_VirtualInput::VirtualInput *pVirtualInput = new module_VirtualInput::VirtualInput();
//		usleep(200000);
		while(scanf("%d %d %d %d %d %d %d %d %d %d\n",
                &trigger_time_us,
                &key1,
                &key2,
                &key3,
                &button,
                &x,
                &y,
                &move_type,
				&step,
				&move_factor) != EOF) {
				if (move_type == -1) break;
				fflush(stdin);
/*				if (move_type_switch != move_type) {
						pVirtualInput->setup(screen_width, screen_height, move_type);
						move_type_switch = move_type;
				}
				for (I0 = 0; I0 < step; ++I0) {
						if (x != no_move)
								x = x * move_factor;

						if (y != no_move)
								y = y * move_factor;

						pVirtualInput->control(press, key1, key2, key3, button, x, y);
						if (trigger_time_us != -1) {
								usleep(trigger_time_us);
								pVirtualInput->control(release, key1, key2, key3, button, no_move, no_move);
						}
								
				}
*/				printf("%d %d %d %d %d %d %d %d %d %d\n", trigger_time_us, key1, key2, key3, button, x, y, move_type, step, move_factor);
				fflush(stdout);
	    }

//		delete pScreenTool;

//		delete pVirtualInput;

		delete pCmdLine;

		exit(0);
}

