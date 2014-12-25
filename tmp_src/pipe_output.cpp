/* ============================================================
File Name     : output.c
Creation Time : 20141015 15:14:24
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int x, y;
	FILE *in, *out;
	char s[256];

	printf("This is output\n");
	while(scanf("move %d %d\n", &x, &y) != EOF)
		printf("receive: %d %d\n", x, y);

	exit(0);
}
