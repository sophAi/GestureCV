/* ======================================================================
File Name     : VirtualInput.h
Creation Time : 20141022 17:27:46
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
#ifndef sophAi_VirtualInput_H_
#define sophAi_VirtualInput_H_

#include <cstring>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <linux/input.h>
#include <linux/uinput.h>

namespace module_VirtualInput {
class VirtualInput
{
	public:

		VirtualInput();

		~VirtualInput();

		bool setup(int &screen_width, 
		    	   int &screen_height, 
				   int &move_type);      //0(kAbsolute) or 1(kRelative)

		void control(int &trigger_type,  //1 for press, 0 for release. Affect to EV_KEY, REL_WHEEL, and REL_HWHEEL.
					 int &key1,          //First key event, ex: KEY_A
					 int &key2,          //Second key event.
					 int &key3,          //Third key event.
					 int &button,        //BTN_TOUCH, 0-5(kAbsolute), BTN_MOUSE, LEFT/MIDDLE/RIGHT, 0-5 (kRelative), REL_WHEEL(with y), or RELHWHEEL(with x)
					 int &x,             //Mouse move that != 0, ABS coordinate (touchscrene) that > -1, or REL_HWHEEL movement that != 0.
					 int &y);            //Mouse move that != 0, ABS coordinate (touchscreen) that > -1, or REL_WHEEL movement that != 0.

		void oneKey(int &trigger, int &key1);

		void twoKeys(int &trigger, int &key1, int &key2);

		void threeKeys(int &trigger, int &key1, int &key2, int &key3);	

		void move(int &x, int &y);


	private:

		int fd;
		int ev_x, ev_y, ev_type, ev_check;
		static struct uinput_user_dev uidev;
		static struct input_event event;

		void release();
};

}
#endif

