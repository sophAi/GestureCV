/* ============================================================
File Name     : GSL_test.cpp
Creation Time : 20141215 09:02:39
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include <stdio.h>
#include <gsl/gsl_sf_bessel.h>

int main (void)
{
		double x = 5.0;
		double y = gsl_sf_bessel_J0(x);
		printf("J0(%g) = %.18e\n", x, y);
		return 0;
}
