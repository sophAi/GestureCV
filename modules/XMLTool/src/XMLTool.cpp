/* ======================================================================
File Name     : XMLTool.cpp
Creation Time : 20141117 16:43:43
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
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
