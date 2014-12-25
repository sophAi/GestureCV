/* ============================================================
File Name     : HandTracking.cpp
Creation Time : 20141218 15:33:57
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#include "HandTracking.h"
using namespace module_HandTracking;

HandTracking::HandTracking()
{

}

HandTracking::~HandTracking()
{

}

HandTracking::DetectHand()
{

                if (left_count > 0) {
                        left_count--;
                }
                if (right_count > 0) {
                        right_count--;
                }
                if (up_count > 0) {
                        up_count--;
                }
                if (down_count > 0) {
                        down_count--;
                }


}

