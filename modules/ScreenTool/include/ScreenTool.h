/* ============================================================
File Name     : ScreenTool.h
Creation Time : 20141030 17:31:39
=============================================================== 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
=============================================================== */
#ifndef sophAi_modules_ScreenTool_H_
#define sophAi_modules_ScreenTool_H_

#include <X11/Xlib.h>

namespace module_ScreenTool {
class ScreenTool
{
	public:

		ScreenTool();
		
		~ScreenTool();

		int screenWidth();

		int screenHeight();

		void X11Screen();
	
	private:

		int screen_width;
		int screen_height;
};
}
#endif

/* Error and warning messages:

E: The error happens.. %s
An error message is shown here.

*/

