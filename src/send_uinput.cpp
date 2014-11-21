/* ======================================================================
File Name     : send_uinput.cpp
Creation Time : 20141015 15:14:24
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
#include <stdio.h>
#include "CmdLine.h"
#include "VirtualInput.h"

int main(int argc, char **argv)
{
		enum KeyType {kRelease, kPressed};
		enum MoveType {kAbsolute, kRelative};
		module_CmdLine::CmdLine *pCmdLine = new module_CmdLine::CmdLine();
//		setvbuf(stdout, 0, _IONBF, 0);
		pCmdLine->setup(argc, argv);
//		std::cout << "Preference file= " << pCmdLine->preferenceFile() << std::endl;
	    ::sleep(1);
	    for (int i = 1; i < 20; ++i) {
				printf("%d %d %d %d %d %d %d %d\n",
		            kPressed,       //trigger_type {kRelease, kPressed}
		            KEY_X,   //key1
					-1,   //key2
					-1,   //key3
					-1,      //button
					-5,       //x
					 5,       //y
					kRelative);      //move_type {kAbsolute, kRelative}
				::usleep(25000);
				fflush(stdout);
				printf("%d %d %d %d %d %d %d %d\n",
					kRelease,       //trigger_type {kRelease, kPressed}
					KEY_X,   //key1
					-1,   //key2
					-1,   //key3
					-1,      //button
					-5,       //x
					 5,       //y
					kRelative);      //move_type {kAbsolute, kRelative}
				fflush(stdout);
				::usleep(50000);
		}

		delete pCmdLine;


		exit(0);
}

