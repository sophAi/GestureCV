/* ============================================================
File Name     : main.cpp
Creation Time : 20141015 15:14:24
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include "CmdLine.h"

int main(int argc, char **argv)
{
		module_CmdLine::CmdLine *pCmdLine = new module_CmdLine::CmdLine();

		pCmdLine->setup(argc, argv);

		delete pCmdLine;

		exit(0);
}

