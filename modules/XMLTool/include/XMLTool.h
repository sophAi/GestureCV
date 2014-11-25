/* ======================================================================
File Name     : XMLTool.h
Creation Time : 20141117 16:42:18
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
#ifndef sophAi_XMLTool_H_
#define sophAi_XMLTool_H_

#include <iostream>
#include <fstream>
#include <vector>

#define VirtualInputXML_X_DIM 4
#define VirtualInputXML_Y_DIM 5

namespace module_XMLTool {
class XMLTool
{
	public:

		XMLTool();

		~XMLTool();

		int setupVirtualInputKeyMap(const char *file_name, std::vector<std::vector<int> > &key_array);

		int setupBinaryFilter(const char *file_name, std::vector<std::vector<int> > &boundary_array);

		int setupCvRGBCamera(const char *file_name, std::vector<std::vector<int> > &camera_array);

		int setupGestureThreshold(const char *file_name, std::vector<std::vector<int> > &threshold_array);
	
		int setupROI(const char *file_name, std::vector<std::vector<int> > &ROI_array);

	private:

		int openXML(char *file_name, int mode);

		int closeXML();

		int readXML();

		int insertXML();

		int deleteXML();

		int replaceXML();
};

}
#endif

/* Error and warning messages:

E: The error happens.. %s
An error message is shown here.

*/

