/* ======================================================================
File Name     : CmdLine.cpp
Creation Time : 20141023 17:29:18
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
#include "CmdLine.h"
using namespace module_CmdLine;


CmdLine::CmdLine(): input_file(NULL), 
			     	output_file(NULL), 
					preference_file(NULL),
					verbose(0)
{

}


void CmdLine::setup(int &argc, char **argv)
{
	    const char *const short_options = "hvi:o:p:";
	    const struct option long_options[] = {
			{"help", 0, NULL, 'h'},
		    {"verbose", 0, NULL, 'v'},
	        {"inputfile", 1, NULL, 'i'},
		    {"outputfile", 1, NULL, 'o'},
			{"preference", 1, NULL, 'p'},
			{NULL, 0, NULL, 0}};
//	    extern char **environ;
	    int next_option;
		int use_default_preference_file = 1;
		std::string default_preference_file;
		program = argv[0];

	    while ((next_option = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
		        switch(next_option) {
						case 'h':
						CmdLine::printUsage(stdout, 0);
						break;
				case 'v':
						CmdLine::verbose = 1;
				        break;
				case 'i':
						input_file = optarg;
						break;
				case 'o':
						output_file = optarg;
						break;
				case 'p':
						preference_file = optarg;
						use_default_preference_file = 0;
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

	    if (use_default_preference_file) {
				if(strncmp(program,".",1) == 0)
				{
						strtok(program,"/");
						program = strtok(NULL,"/");
				}

				default_preference_file.append("~/.").append(program);
				preference_file = strdup(default_preference_file.c_str());
	    }

	    if (CmdLine::verbose) {
				printf("Program name: %s\n", program);
				printf("Preference file will be stored at: %s\n", 
					preference_file);
				printf("Input file: %s\n", input_file);
			    printf("Output file: %s\n", output_file);
		        for (int i = 0; i < argc; ++i)
				            printf("Argument %d: %s\n", i, argv[i]);

	    }
}


CmdLine::~CmdLine()
{

}

void CmdLine::printUsage(FILE *stream, int exit_code)
{
		fprintf(stream, 
			"Usage: %s options [-i inputfile ... ]\n", program);
		fprintf(stream,
            "  -h, --help         Display this usage information.\n"
            "  -i, --input        Input file.\n"
            "  -o, --output       Output file.\n"
            "  -p, --preference   Preference file.\n"
            "  -v, --verbose      Print verbose messages.\n");

	    exit(exit_code);
}

char *CmdLine::inputFile()
{
		return input_file;
}

char *CmdLine::outputFile()
{
		return output_file;
}

char *CmdLine::preferenceFile()
{
		return preference_file;
}
