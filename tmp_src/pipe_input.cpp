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
	int c;
	FILE *in, *out;

//	while((c = getchar()) != EOF)
//		putchar(c);

	for (int i = 1; i < 100; i++)
		printf("move %d %d\n",i,i+100);

	exit(0);
}
