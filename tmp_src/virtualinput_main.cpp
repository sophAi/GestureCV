/* ============================================================
File Name     : VirtualInput.cpp
Creation Time : 20141015 15:14:24
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>
#include <iostream>
#include <typeinfo>
#include <X11/Xlib.h>
#include "VirtualInput.h"
#define max_char_length 128

char *program;

void printUsage(FILE *stream, int exit_code)
{
	fprintf(stream, "Usage: %s options [-i inputfile ... ]\n", program);
	fprintf(stream,
			"  -h, --help         Display this usage information.\n"
			"  -i, --input        Input file.\n"
			"  -o, --output       Output file.\n"
			"  -p, --preference   Preference file.\n"
			"  -v, --verbose      Print verbose messages.\n");
	exit(exit_code);
}

int main(int argc, char **argv)
{
	const char *const short_options = "hvi:o:p:";
	const struct option long_options[] = {
		{"help", 0, NULL, 'h'},
		{"verbose", 0, NULL, 'v'},
		{"inputfile", 1, NULL, 'i'},
		{"outputfile", 1, NULL, 'o'},
		{"preference", 1, NULL, 'p'},
		{NULL, 0, NULL, 0}};
	const char *input_file = NULL;
	const char *output_file = NULL;
//	extern char **environ;
	int verbose = 0;
	int next_option;
	int use_default_preference_file = 1;
    char default_preference_file[max_char_length] = "~/.";
    char *preference_file = NULL;

    program = argv[0];
    if((int)strlen(program) > max_char_length) 
    {
      printf("Error! Program %s exceed %d characters\n",program, max_char_length);
      exit(1);
    }
    if(strncmp(program,".",1) == 0)
    {
      strtok(program,"/");
      program = strtok(NULL,"/");
    }
    strcat(default_preference_file, (char *)program);

	while ((next_option = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) { 
		switch(next_option) {
		case 'h':
            printUsage(stdout, 0);
			break;
		case 'v':
            verbose = 1;
			break;
		case 'i':
			input_file = optarg;
			printf("Input file: %s\n", input_file);
			break;
		case 'o':
			output_file = optarg;
			printf("Output file: %s\n", output_file);
			break;
		case 'p':
			preference_file = optarg;
			use_default_preference_file = 0;
			printf("Preference file: %s\n", preference_file);
			break;
		case ':':

			break;

		case '?':
			printUsage(stderr, 1);
			break;
		case -1:
			break;
		default:
			abort();
		}
	}
	if (verbose) {
		for (int i = 0; i < argc; ++i)
			printf("Argument %d: %s\n", i, argv[i]);
	}

	if (use_default_preference_file) {
		preference_file = default_preference_file;
	}

    printf("Program name: %s\n", program);
    printf("Preference file will be stored at: %s\n", preference_file);

	Display *disp=XOpenDisplay(NULL);
	Screen *scrn = DefaultScreenOfDisplay(disp);
	int screen_height = scrn->height;
	int screen_width = scrn->width;
//	std::cout << "main screen_height: " << screen_height << std::endl;
//	std::cout << "main screen_width: " << screen_width << std::endl;
//  Init
	module_VirtualInput::VirtualInput *pVirtualInput = new module_VirtualInput::VirtualInput();
//  Setup
	int move_type;
	move_type = 1;
    pVirtualInput->setup(screen_width, screen_height, move_type);
	int trigger_type;
	int key1 = -1;
	int key2 = -1;
	int key3 = -1;
	int button = REL_WHEEL;
	int x = -1;
	int y = -1;
	for (int i = 0; i < 10; ++i) {
		trigger_type = 1;
 	pVirtualInput->control(trigger_type, key1, key2, key3, button, x, y);
	::usleep(50);
	trigger_type = 0;
	std::cout << "i= " << i << std::endl;
	pVirtualInput->control(trigger_type, key1, key2, key3, button, x, y);
	sleep(1);
	}
	int dx, dy;
	x=110;
	y=200;
	dx=5;
	dy=5;
	trigger_type = 0;
	key1 = -1;
	key2 = -2;
	key3 = -3;
	button = -1;
	for (int i = 100; i <	x; ++i) {
		for (int j = 100; j < y; ++j) {
			dx=i+j;
			dy=j;
			pVirtualInput->control(trigger_type, key1, key2, key3, button, dx, dy);
			usleep(5000);
		}
	}
	x=5;
	y=100;
	dx=1;
	dy=1;
	button = BTN_LEFT;
	move_type = 1;
	std::cout << "Switch to relative" << std::endl;
	pVirtualInput->setup(screen_width, screen_height, move_type);
	for (int i = 0; i <	x; ++i) {
		trigger_type = 1;
		for (int j = 0; j < y; ++j) {
			pVirtualInput->control(trigger_type, key1, key2, key3, button, dx, dy);
			usleep(10000);
		}
		trigger_type = 0;
	}
	move_type = 0;
	pVirtualInput->setup(screen_width, screen_height, move_type);
    x=60;
    y=150;
    dx=5;
    dy=5;
	button = BTN_0;
    for (int i = 50; i < x; ++i) {
		trigger_type = 1;
        for (int j = 50; j < y; ++j) {
            dx=i+j;
            dy=j;
			pVirtualInput->control(trigger_type, key1, key2, key3, button, dx, dy);
            usleep(5000);
        }
		trigger_type = 0;
    }


//  Input: while(scanf("keyword %d %d ...\n", &x1, &x2) != EOF)

//  Output: printf 
    delete pVirtualInput;
	return 0;
}

