/* ============================================================
File Name     : main.cpp
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
char *program;
#define max_char_length 128
void print_usage(FILE *stream, int exit_code)
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
	extern char **environ;
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
            print_usage(stdout, 0);
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
			print_usage(stderr, 1);
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

//  Initiate

//  Setup

//  Compute

//  Input: while(scanf("keyword %d %d ...\n", &x1, &x2) != EOF)

//  Output: printf 

	return 0;
}

