#ifndef _Distribution_H_
#define _Distribution_H_

#include <cstring>

namespace module_Distribution {
class Distribution
{
public:

		Distribution(int image_x_dim,
	    			 int image_y_dim);

		virtual ~Distribution();

/*		void Distribution_2D(const cv::Mat &binaryData, 
						     cv::Mat &horizontalDistribution, 
						     cv::Mat &verticalDistribution,
						     int &xmean,
						     int &xvar, 
						     int &ymean, 
						     int &yvar);
*/
		void imageROI(int ROI_x_lower, int ROI_x_upper, int ROI_y_lower, int ROI_y_upper);

		void imageDist2d(unsigned char *input_array,
				         int *x_dist_array,
				         int *y_dist_array);

		int imageDistMean(int *dist_array, int lower_id, int upper_id, int threshold);

		int imageDistVar(int *dist_array,
						  int *dist_mean);

		int imageDistSkew(int *dist_array,
						   int *dist_mean);

		int imageDistKurtosis(int *dist_array,
                               int *mean);

//		void dist_3d(const int input_array[],
//				     unsigned int x_dist_array[],
//				     unsigned int y_dist_array[],
//				     unsigned int z_dist_array[]);

private:
		int image_x_dim;
		int image_y_dim;
		int ROI_x_lower, ROI_y_lower, ROI_x_upper, ROI_y_upper, ROI_x_length, ROI_y_length;
};
}
#endif
