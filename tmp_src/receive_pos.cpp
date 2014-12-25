/* ============================================================
File Name     : receive_pos.cpp
Creation Time : 20141015 15:14:24
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include <iostream>
#include <stdio.h>
#include "CmdLine.h"
#include "VirtualInput.h"

int main(int argc, char **argv)
{
		module_CmdLine::CmdLine *pCmdLine = new module_CmdLine::CmdLine();
		pCmdLine->setup(argc, argv);
		int pos_x = 0, pos_y = 0, pos_pre_x = 0, pos_pre_y = 0, diff_x = 0, diff_y = 0;
		int camera_x = 0;
		int camera_y = 0;
		setvbuf(stdout, 0, _IOLBF, 64);
		scanf("%d %d %d %d\n", &camera_x, &camera_y, &pos_pre_x, &pos_pre_y);
		int threshold_key_x = camera_x*40/1280;
		int threshold_key_y = camera_y*50/720;
		int threshold_move_x = camera_x*10/1280;
		int threshold_move_y = camera_y*10/720;
		while (scanf("%d %d %d %d\n",&camera_x, &camera_y, &pos_x, &pos_y) != EOF) {
				fflush(stdin);
				if (diff_y < -threshold_key_y) {
						diff_x = pos_pre_x - pos_x;
						diff_y = pos_y - pos_pre_y;
						pos_pre_x = pos_x;
						pos_pre_y = pos_y;
						printf("%d %d %d %d %d %d %d %d\n", 1, KEY_LEFTALT, KEY_X, -1, -1, 0, 0, 1);
//						fflush(stdout);
//						usleep(250);
						printf("%d %d %d %d %d %d %d %d\n", 0, KEY_LEFTALT, KEY_X, -1, -1, 0, 0, 1);
						fflush(stdout);
						continue;
				}

				if (diff_y > threshold_key_y) {
						diff_x = pos_pre_x - pos_x;
						diff_y = pos_y - pos_pre_y;
						pos_pre_x = pos_x;
						pos_pre_y = pos_y;
						printf("%d %d %d %d %d %d %d %d\n", 1, -1, -1, -1, BTN_LEFT, 0, 0, 1);
//						fflush(stdout);
//						usleep(50);
						printf("%d %d %d %d %d %d %d %d\n", 0, -1, -1, -1, BTN_LEFT, 0, 0, 1);
						fflush(stdout);
						continue;
				}

				if (diff_x < -threshold_key_x) {
						diff_x = pos_pre_x - pos_x;
						diff_y = pos_y - pos_pre_y;
						pos_pre_x = pos_x;
						pos_pre_y = pos_y;
						printf("%d %d %d %d %d %d %d %d\n", 1, KEY_LEFT, -1, -1, -1, 0, 0, 1);
//						fflush(stdout);
//						usleep(50);
						printf("%d %d %d %d %d %d %d %d\n", 0, KEY_LEFT, -1, -1, -1, 0, 0, 1);	
						fflush(stdout);
						continue;
				}

				if (diff_x > threshold_key_x) {
						diff_x = pos_pre_x - pos_x;
						diff_y = pos_y - pos_pre_y;
						pos_pre_x = pos_x;
						pos_pre_y = pos_y;
						printf("%d %d %d %d %d %d %d %d\n", 1, KEY_RIGHT, -1, -1, -1, 0, 0, 1);
//						fflush(stdout);
//						usleep(50);
						printf("%d %d %d %d %d %d %d %d\n", 0, KEY_RIGHT, -1, -1, -1, 0, 0, 1);
						fflush(stdout);
						continue;
				}

				if (abs(diff_y) > threshold_move_y && abs(diff_x) > threshold_move_x) {
						diff_x = pos_pre_x - pos_x;
						diff_y = pos_y - pos_pre_y;
						pos_pre_x = pos_x;
						pos_pre_y = pos_y;
						printf("%d %d %d %d %d %d %d %d\n", 1, -1, -1, -1, -1, diff_x, diff_y, 1);
						fflush(stdout);
						continue;
				} else if (abs(diff_y) > threshold_move_y) {
						diff_x = pos_pre_x - pos_x;
						diff_y = pos_y - pos_pre_y;
						pos_pre_x = pos_x;
						pos_pre_y = pos_y;
						printf("%d %d %d %d %d %d %d %d\n", 1, -1, -1, -1, -1, 0, diff_y, 1);
						fflush(stdout);
						continue;
				} else if (abs(diff_x) > threshold_move_x) {
						diff_x = pos_pre_x - pos_x;
						diff_y = pos_y - pos_pre_y;
						pos_pre_x = pos_x;
						pos_pre_y = pos_y;
						printf("%d %d %d %d %d %d %d %d\n", 1, -1, -1, -1, -1, diff_x, 0, 1);
						fflush(stdout);
						continue;
				}	

				diff_x = pos_pre_x - pos_x;
				diff_y = pos_y - pos_pre_y;
				pos_pre_x = pos_x;
				pos_pre_y = pos_y;
	    }


		delete pCmdLine;

		exit(0);
}

