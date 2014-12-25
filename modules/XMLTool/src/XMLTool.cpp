/* ============================================================
File Name     : XMLTool.cpp
Creation Time : 20141117 16:43:43
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include "XMLTool.h"
using namespace module_XMLTool;

XMLTool::XMLTool()
{

}

XMLTool::~XMLTool()
{
		XMLTool::closeXML();
}

int XMLTool::setupVirtualInputKeyMap(const char *file_name, std::vector<std::vector<int> > &key_array)
{
	
		std::string XML_header, XML_name, XML_description, XML_tag;
		std::ifstream XML_file;
		XML_file.open(file_name, std::ios::in);
		if(!XML_file.good()) return -1;
		key_array[0][2] = -1;
		key_array[0][3] = -1;
		while (!XML_file.eof()) {
			getline(XML_file, XML_tag);
			if (XML_tag.find("<detect_mode>")!=std::string::npos) {
					XML_file >> XML_tag;
					if (XML_tag == "key") {
						key_array[0][0] = 0;
					} else if (XML_tag == "mouse") {
						key_array[0][0] = 1;
					} else if (XML_tag == "both") {
						key_array[0][0] = 2;
					}
			}
			if (XML_tag.find("<move_type>")!=std::string::npos) {
					XML_file >> XML_tag;
					if (XML_tag == "absolute") {
						key_array[0][1] = 0;
					} else if (XML_tag == "relative") {
						key_array[0][1] = 1;
					}
			}
			if (XML_tag.find("<key1>")!=std::string::npos) {
					XML_file >> key_array[1][0] >> key_array[1][1] >> key_array[1][2] >> key_array[1][3];
			}
			if (XML_tag.find("<key2>")!=std::string::npos) {
					XML_file >> key_array[2][0] >> key_array[2][1] >> key_array[2][2] >> key_array[2][3];
			}
			if (XML_tag.find("<key3>")!=std::string::npos) {
					XML_file >> key_array[3][0] >> key_array[3][1] >> key_array[3][2] >> key_array[3][3];
			}
			if (XML_tag.find("<button>")!=std::string::npos) {
					XML_file >> key_array[4][0] >> key_array[4][1] >> key_array[4][2] >> key_array[4][3];
			}
			if (XML_tag.find("<step>")!=std::string::npos) {
					XML_file >> key_array[5][0] >> key_array[5][1] >> key_array[5][2] >> key_array[5][3];
			}
			if (XML_tag.find("<move_factor>")!=std::string::npos) {
					XML_file >> key_array[6][0] >> key_array[6][1] >> key_array[6][2] >> key_array[6][3];
			}
			if (XML_tag.find("<interval_us>")!=std::string::npos) {
					XML_file >> key_array[7][0] >> key_array[7][1] >> key_array[7][2] >> key_array[7][3];
			}
		}
/*		for (int i = 0; i < VirtualInputXML_Y_DIM; ++i) {
				for (int j = 0; j < VirtualInputXML_X_DIM; ++j) {
						std::cout << key_array[i][j] << std::endl;
				}
		}
*/
		XML_file.close();
		return 0;
		
}

int XMLTool::setupBinaryFilter(const char *file_name, std::vector<std::vector<int> > &boundary_array)
{
		std::string XML_header, XML_name, XML_description, XML_tag;
        std::ifstream XML_file;
        XML_file.open(file_name, std::ios::in);
        if(!XML_file.good()) return -1;
		while (!XML_file.eof()) {
            getline(XML_file, XML_tag);
            if (XML_tag.find("<lower1>")!=std::string::npos) {
					XML_file >> boundary_array[0][0];		
			}
            if (XML_tag.find("<upper1>")!=std::string::npos) {
					XML_file >> boundary_array[0][1];		
			}
            if (XML_tag.find("<lower2>")!=std::string::npos) {
					XML_file >> boundary_array[1][0];		
			}
            if (XML_tag.find("<upper2>")!=std::string::npos) {
					XML_file >> boundary_array[1][1];		
			}
            if (XML_tag.find("<lower3>")!=std::string::npos) {
					XML_file >> boundary_array[2][0];		
			}
            if (XML_tag.find("<upper3>")!=std::string::npos) {
					XML_file >> boundary_array[2][1];		
			}
		}
		XML_file.close();
		return 0;
}

int XMLTool::setupCvRGBCamera(const char *file_name, std::vector<std::vector<float> > &camera_array)
{
		std::string XML_header, XML_name, XML_description, XML_tag;
        std::ifstream XML_file;
        XML_file.open(file_name, std::ios::in);
        if(!XML_file.good()) return -1;
		while (!XML_file.eof()) {
            getline(XML_file, XML_tag);
            if (XML_tag.find("<camera_id>")!=std::string::npos) {
					XML_file >> camera_array[0][0];
			}
            if (XML_tag.find("<camera_x>")!=std::string::npos) {
					XML_file >> camera_array[0][1];
			}
            if (XML_tag.find("<camera_y>")!=std::string::npos) {
					XML_file >> camera_array[0][2];
			}
            if (XML_tag.find("<camera_fps>")!=std::string::npos) {
					XML_file >> camera_array[0][3];
			}
            if (XML_tag.find("<camera_brightness>")!=std::string::npos) {
					XML_file >> camera_array[0][4];
			}
            if (XML_tag.find("<camera_contrast>")!=std::string::npos) {
					XML_file >> camera_array[0][5];
			}
		}
		XML_file.close();
		return 0;
}

int XMLTool::setupGestureThreshold(const char *file_name, std::vector<std::vector<int> > &threshold_array)
{
        std::string XML_header, XML_name, XML_description, XML_tag;
        std::ifstream XML_file;
        XML_file.open(file_name, std::ios::in);
        if(!XML_file.good()) return -1;
		while (!XML_file.eof()) {
            getline(XML_file, XML_tag);
            if (XML_tag.find("<threshold_key_left>")!=std::string::npos) {
					XML_file >> threshold_array[0][0];
			}
            if (XML_tag.find("<threshold_key_right>")!=std::string::npos) {
					XML_file >> threshold_array[0][1];
			}
            if (XML_tag.find("<threshold_key_up>")!=std::string::npos) {
					XML_file >> threshold_array[0][2];
			}
            if (XML_tag.find("<threshold_key_down>")!=std::string::npos) {
					XML_file >> threshold_array[0][3];
			}
            if (XML_tag.find("<threshold_move_x>")!=std::string::npos) {
					XML_file >> threshold_array[0][4];
			}
            if (XML_tag.find("<threshold_move_y>")!=std::string::npos) {
					XML_file >> threshold_array[0][5];
			}
            if (XML_tag.find("<count_threshold_short>")!=std::string::npos) {
					XML_file >> threshold_array[0][6];
			}
            if (XML_tag.find("<count_threshold_long>")!=std::string::npos) {
					XML_file >> threshold_array[0][7];
			}
		}
        XML_file.close();
        return 0;
}

int XMLTool::setupROI(const char *file_name, std::vector<std::vector<int> > &ROI_array)
{
        std::string XML_header, XML_name, XML_description, XML_tag;
        std::ifstream XML_file;
        XML_file.open(file_name, std::ios::in);
        if(!XML_file.good()) return -1;
		while (!XML_file.eof()) {
            getline(XML_file, XML_tag);
            if (XML_tag.find("<cut_x_lower>")!=std::string::npos) {
					XML_file >> ROI_array[0][0];
			}
            if (XML_tag.find("<cut_x_upper>")!=std::string::npos) {
					XML_file >> ROI_array[0][1];
			}
            if (XML_tag.find("<cut_y_lower>")!=std::string::npos) {
					XML_file >> ROI_array[0][2];
			}
            if (XML_tag.find("<cut_y_upper>")!=std::string::npos) {
					XML_file >> ROI_array[0][3];
			}
            if (XML_tag.find("<sum_threshold>")!=std::string::npos) {
					XML_file >> ROI_array[0][4];
			}
		}
        XML_file.close();
        return 0;
}

int XMLTool::openXML(char *file_name, int mode)
{
//mode: 0 = read, 1 = write
	
}

int XMLTool::closeXML()
{

}

int XMLTool::readXML()
{

}

int XMLTool::insertXML()
{

}

int XMLTool::deleteXML()
{

}

int XMLTool::replaceXML()
{

}
