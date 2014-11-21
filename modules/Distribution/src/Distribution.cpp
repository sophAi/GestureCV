/* ======================================================================
File Name     : histogram.cpp
Creation Time : 20140925 17:23:55
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
========================================================================= */
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


/*void Distribution::Distribution_2D(const cv::Mat &binaryData,
								   cv::Mat &xDistribution, 
								   cv::Mat &yDistribution,
								   int &xmean,
								   int &xvar,
								   int &ymean,
								   int &yvar)
// Input binaryData and output x-distribution and y-distribution

{
// Create 1xbinaryData.cols matrix with all zeros
		xDistribution = cv::Mat::zeros(1, 
								       binaryData.cols, 
								       CV_32SC1);
// Create binaryData.rowsx1 matrix with all zeros
		yDistribution = cv::Mat::zeros(binaryData.rows, 
								       1, 
								       CV_32SC1);

//  Assigned the matrix data to binaryArray, horizontalArray, and verticalArray
		uchar *binaryArray = binaryData.data;
		uint32_t *xArray = (uint32_t *)xDistribution.data;
		uint32_t *yArray = (uint32_t *)yDistribution.data;

		for (int y_id = 0; y_id < binaryData.rows; ++y_id)
		{
				for (int x_id = 0; x_id < binaryData.cols; ++x_id)
				{
						if (*binaryArray != 0)//Scan from the beginning address of binaryArray
						{
								++xArray[x_id];
								++yArray[y_id];
						}

						++binaryArray;//Scan next data of *binaryArray. binaryArray is representing the address
				}		
		}
		
}
*/

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
		int sum = 0;
		for (int i = lower_id; i < upper_id; ++i) {
				weight_sum = weight_sum + i * (*(dist_array+i));
				sum = sum + (*(dist_array+i));
		}
//		std::cout << "sum=" << sum <<std::endl;
		if (sum > threshold) {
				return (int)((float)weight_sum/(float)sum);
		} else {
				return -1;
		}
}

int Distribution::imageDistVar(int *dist_array, 
				  int *dist_mean)
{

}

int Distribution::imageDistSkew(int *dist_array, 
			       int* dist_mean)
{

}

int Distribution::imageDistKurtosis(int *dist_array, 
								 int *dist_mean)
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
