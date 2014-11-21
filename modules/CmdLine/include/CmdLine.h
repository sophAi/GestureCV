/* ======================================================================
File Name     : CmdLine.h
Creation Time : 20141023 17:20:58
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
#ifndef sophAi_CmdLine_H_
#define sophAi_CmdLine_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <errno.h>
#include <iostream>

namespace module_CmdLine{
class CmdLine
{
	public:

	    CmdLine();

		~CmdLine();

		void setup(int &argc, char** argv);

		void printUsage(FILE *stream, int exit_code);

		char *inputFile();
	
		char *outputFile();

		char *preferenceFile();

	private:
		
		int verbose;
		char *program;
		char *input_file;
		char *output_file;
		char *preference_file;
};
}
#endif

/* Error and warning messages:

E: The error happens.. %s
An error message is shown here.

*/

