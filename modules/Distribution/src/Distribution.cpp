/* ===========================================================
File Name     : histogram.cpp
Creation Time : 20140925 17:23:55
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include "Distribution.h"
#include "iostream"
using namespace module_Distribution;

Distribution::Distribution(int x_dim, 
						   int y_dim):image_x_dim(x_dim),
									  image_y_dim(y_dim),
									  ROI_x_lower(0), 
									  ROI_x_upper(x_dim), 
									  ROI_y_lower(0), 
									  ROI_y_upper(y_dim),
									  ROI_x_length(x_dim),
									  ROI_y_length(y_dim)
{
//		dist_instance++;
}

Distribution::~Distribution()
{
//		dist_instance--;
}
								
void Distribution::imageROI(int x_lower, int x_upper, int y_lower, int y_upper)
{
		this->ROI_x_lower = x_lower; 
		this->ROI_x_upper = x_upper; 
		this->ROI_y_lower = y_lower; 
		this->ROI_y_upper = y_upper;
		this->ROI_x_length = x_upper - x_lower + 1;
		this->ROI_y_length = y_upper - y_lower + 1;
}


void Distribution::imageDist2d(unsigned char *input_array,
						   int *x_dist_array,
						   int *y_dist_array)
{

		memset(x_dist_array, 0, sizeof(int)*ROI_x_length);
		memset(y_dist_array, 0, sizeof(int)*ROI_y_length);

		for (int y_id = 0; y_id < ROI_y_length; ++y_id) {
				for (int x_id = 0; x_id < ROI_x_length; ++x_id) {
						if(*(input_array+(ROI_y_lower+y_id)*image_x_dim+(ROI_x_lower+x_id)) != 0) {
								++x_dist_array[x_id];
								++y_dist_array[y_id];
						}
//						++input_array;
				}
		}

}

int Distribution::imageDistMean(int *dist_array, int lower_id, int upper_id, int threshold)
{
		int weight_sum = 0;
		Distribution::dist_sum = 0;
		for (int i = lower_id; i < upper_id; ++i) {
				weight_sum = weight_sum + i * (*(dist_array+i));
				Distribution::dist_sum = Distribution::dist_sum + (*(dist_array+i));
		}
//		std::cout << "sum=" << sum <<std::endl;
		if (Distribution::dist_sum > threshold) {
				Distribution::image_dist_mean = (int)((float)weight_sum/(float)Distribution::dist_sum);
				return Distribution::image_dist_mean;
		} else {
				return -1;
		}
}

int Distribution::imageDistVar(int *dist_array, int lower_id, int upper_id)
{
		int diff_temp, var_x = 0, var_xi = 0;
		for (int i = lower_id; i < upper_id; ++i) {
				diff_temp = *(dist_array+i) - Distribution::image_dist_mean;
				var_xi = var_xi + i * diff_temp;
				var_x = var_x + i * diff_temp*diff_temp;
		}
		return (var_x - (var_xi * var_xi)/Distribution::dist_sum)/(Distribution::dist_sum-1);
}

int Distribution::imageDistSkew(int *dist_array, int lower_id, int upper_id)
{

}

int Distribution::imageDistKurt(int *dist_array, int lower_id, int upper_id)
{

}
/*
 * Measure the x-direction and y-direction distributions of non-zero counting of input_array.
 * The dimension of the input_array is defined by input_array_x_dim and input_array_y_dim.

{
		for (int y_id = 0; y_id < input_array_y_dim; ++y_id)
		{
				for (int x_id = 0; x_id < input_array_x_dim; ++x_id)
				{
						if (*input_array != 0)
						{
								++x_dist_array[x_id];
								++y_dist_array[y_id];
						}
						++input_array;
				}
		}
}



*/
/*
void Distribution::dist_3d(const int *input_array,
						   unsigned int *x_dist_array,
						   unsigned int *y_dist_array,
						   unsigned int *z_dist_array)
 * Measure the x-, y-, and z-direction distributions of non-zero counting of input_array.
 * The dimension of the input_array is defined by input_array_(x,y,z)_dim.
{
		for (int z_id = 0; z_id < input_array_z_dim; ++z_id)
		{
				for (int y_id = 0; y_id < input_array_y_dim; ++y_id)
				{
						for (int x_id = 0; x_id < input_array_x_dim; ++x_id)
						{
								if (input_array != 0)
								{
										++x_dist_array[x_id];
										++y_dist_array[y_id];
										++z_dist_array[z_id];
				    			}
							    ++input_array;
						}
				}		
		}
}
*/
