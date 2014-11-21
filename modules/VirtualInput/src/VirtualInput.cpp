/* ======================================================================
File Name     : VirtualInput.cpp
Creation Time : 20141023 10:47:23
========================================================================= 
Copyright (c),2014-, Po-Jen Hsu.  Contact: clusterga@gmail.com
See the README file in the top-level directory for license.
========================================================================= */
#include "VirtualInput.h"
using namespace module_VirtualInput;

struct uinput_user_dev VirtualInput::uidev;
struct input_event VirtualInput::event;

VirtualInput::VirtualInput():fd(-1)
{

}

bool VirtualInput::setup(int &screen_width, int &screen_height, int &move_type)
{
		if (fd != -1)
				VirtualInput::release();

		fd = ::open("/dev/uinput", O_WRONLY | O_NONBLOCK);

		if (fd == 0) {
				std::cerr << "Unable to open /dev/uinput" << 
					std::endl;
				return false;
		}

		::strncpy(uidev.name, "Virtual Input Device", UINPUT_MAX_NAME_SIZE);

		uidev.id.bustype = BUS_USB;
		uidev.id.vendor = 0x1;
		uidev.id.product = 0x1;
		uidev.id.version = UINPUT_VERSION;

//  Initiate all functions
		::ioctl(fd, UI_SET_EVBIT, EV_KEY);

		for (int i = 0; i < 256; ++i) {
				::ioctl(fd, UI_SET_KEYBIT, i);
		}
	
	    if (move_type == 0) {   //ABS
				VirtualInput::ev_type = EV_ABS;
				VirtualInput::ev_x = ABS_X;
				VirtualInput::ev_y = ABS_Y;
				VirtualInput::ev_check = -1;
				VirtualInput::uidev.absmin[ABS_X] = 0;
				VirtualInput::uidev.absmax[ABS_X] = screen_width;
			    VirtualInput::uidev.absfuzz[ABS_X]=0;
				VirtualInput::uidev.absflat[ABS_X]=0;
				VirtualInput::uidev.absmin[ABS_Y] = 0;
				VirtualInput::uidev.absmax[ABS_Y] = screen_height;
			    VirtualInput::uidev.absfuzz[ABS_Y]=0;
				VirtualInput::uidev.absflat[ABS_Y]=0;
			    ::ioctl(fd, UI_SET_EVBIT, EV_ABS);
				::ioctl(fd, UI_SET_ABSBIT, ABS_X);
				::ioctl(fd, UI_SET_ABSBIT, ABS_Y);
				::ioctl(fd, UI_SET_ABSBIT, ABS_PRESSURE);
				::ioctl(fd, UI_SET_KEYBIT, BTN_TOUCH);
		} else {              //REL
				VirtualInput::ev_type = EV_REL;
				VirtualInput::ev_x = REL_X;
				VirtualInput::ev_y = REL_Y;
				VirtualInput::ev_check = 0;
		    	::ioctl(fd, UI_SET_KEYBIT, BTN_MOUSE);
				::ioctl(fd, UI_SET_EVBIT, EV_REL);
				::ioctl(fd, UI_SET_RELBIT, REL_X);
				::ioctl(fd, UI_SET_RELBIT, REL_Y);
				::ioctl(fd, UI_SET_KEYBIT, BTN_LEFT);
				::ioctl(fd, UI_SET_KEYBIT, BTN_RIGHT);
				::ioctl(fd, UI_SET_KEYBIT, BTN_MIDDLE);
		}

		::ioctl(fd, UI_SET_RELBIT, REL_WHEEL);
		::ioctl(fd, UI_SET_RELBIT, REL_HWHEEL);
		::ioctl(fd, UI_SET_KEYBIT, BTN_0);
		::ioctl(fd, UI_SET_KEYBIT, BTN_1);
		::ioctl(fd, UI_SET_KEYBIT, BTN_2);
		::ioctl(fd, UI_SET_KEYBIT, BTN_3);
		::ioctl(fd, UI_SET_KEYBIT, BTN_4);
		::ioctl(fd, UI_SET_KEYBIT, BTN_5);

		::write(fd, &VirtualInput::uidev, 
			sizeof(struct uinput_user_dev));

		if (::ioctl(fd, UI_DEV_CREATE) != 0) {
				std::cerr << "Unable to create uinput device." << 
					std::endl;
				return false;
		}

		::usleep(25000); //At least more than 10000ms delays for device initiation                                                         
		return true;
    
}

VirtualInput::~VirtualInput()
{
		VirtualInput::release();
}

void VirtualInput::control(int &trigger_type,
						   int &key1,
						   int &key2,
						   int &key3,
						   int &button,
						   int &x,
						   int &y)
{
//		memset(&event, 0, sizeof(struct input_event));
		::gettimeofday(&event.time, NULL);

		if (key1 > 0) {
				event.type = EV_KEY;
				event.code = key1;
				event.value = trigger_type;
				::write(fd, &event, sizeof(struct input_event));
		}

		if (key2 > 0) {
				event.type = EV_KEY;
				event.code = key2;
				event.value = trigger_type;
				::write(fd, &event, sizeof(struct input_event));
		}

		if (key3 > 0) {
				event.type = EV_KEY;
				event.code = key3;
				event.value = trigger_type;
				::write(fd, &event, sizeof(struct input_event));
		}

		if (button > 0) {
				if (button == REL_WHEEL) { //must be used with EV_REL and BTN_MOUSE
						event.type = EV_REL;
						event.code = REL_WHEEL;
						event.value = y;
				} else if (button == REL_HWHEEL) { //must be used with EV_REL and BTN_MOUSE
						event.type = EV_REL;
						event.code = REL_HWHEEL;
						event.value = x;
				} else {
						event.type = EV_KEY;
						event.code = button;
						event.value = trigger_type;
				}
				::write(fd, &event, 
					sizeof(struct input_event));
		}

		if (x != VirtualInput::ev_check) {
			    event.type = VirtualInput::ev_type;
				event.code = VirtualInput::ev_x;
				event.value = x;
				::write(fd, &event, sizeof(struct input_event));
		}

		if (y != VirtualInput::ev_check) {
			    event.type = VirtualInput::ev_type;
			    event.code = VirtualInput::ev_y;
			    event.value = y;
				::write(fd, &event, sizeof(struct input_event));

		}

		event.type = EV_SYN;
		event.code = SYN_REPORT;
		event.value = 0;
		::write(fd, &event, sizeof(struct input_event));

}


void VirtualInput::move(int &x, int &y)
{
		memset(&event, 0, sizeof(struct input_event));
		::gettimeofday(&event.time, NULL);
		event.type = VirtualInput::ev_type;
		event.code = VirtualInput::ev_x;
		event.value = x;
		::write(fd, &event, sizeof(struct input_event));

//		::gettimeofday(&event.time, NULL);
//		memset(&event, 0, sizeof(struct input_event));
		event.type = VirtualInput::ev_type;
		event.code = VirtualInput::ev_y;
		event.value = y;
		::write(fd, &event, sizeof(struct input_event));

//		::gettimeofday(&event.time, NULL);
//		memset(&event, 0, sizeof(struct input_event));
//		event.type = VirtualInput::ev_type;
//		event.code = ABS_PRESSURE;
//		event.value = 128;
		::write(fd, &event, sizeof(struct input_event));

		event.type = EV_SYN;
		event.code = SYN_REPORT;
		event.value = 0;
		::write(fd, &event, sizeof(struct input_event));
}

void VirtualInput::oneKey(int &trigger_type, int &key1)
{
	    ::gettimeofday(&event.time, NULL);

		if (key1 > 0) {
				event.type = EV_KEY;
		        event.code = key1;
		        event.value = trigger_type;
		        ::write(fd, &event, 
					sizeof(struct input_event));
	    }

		event.type = EV_SYN;
		event.code = SYN_REPORT;
	    event.value = 0;
		::write(fd, &event, sizeof(struct input_event));
}

void VirtualInput::twoKeys(int &trigger_type, int &key1, int &key2)
{
		::gettimeofday(&event.time, NULL);
		memset(&event, 0, sizeof(struct input_event));

	    if (key1 > 0) {
				event.type = EV_KEY;
				event.code = key1;
				event.value = trigger_type;
				::write(fd, &event, sizeof(struct input_event));
		}

		if (key2 > 0) {
				event.type = EV_KEY;
		        event.code = key2;
				event.value = trigger_type;
		        ::write(fd, &event, sizeof(struct input_event));
		}

		event.type = EV_SYN;
	    event.code = SYN_REPORT;
		event.value = 0;
	    ::write(fd, &event, sizeof(struct input_event));
}


void VirtualInput::threeKeys(int &trigger_type, int &key1, int &key2, int &key3)
{
		::gettimeofday(&event.time, NULL);
		memset(&event, 0, sizeof(struct input_event));

		if (key1 > 0) {
				event.type = EV_KEY;
				event.code = key1;
				event.value = trigger_type;
				::write(fd, &event, sizeof(struct input_event));
		}

		if (key2 > 0) {
				event.type = EV_KEY;
				event.code = key2;
				event.value = trigger_type;
				::write(fd, &event, sizeof(struct input_event));
		}

		if (key3 > 0) {
				event.type = EV_KEY;
				event.code = key3;
				event.value = trigger_type;
				::write(fd, &event, sizeof(struct input_event));
		}

		event.type = EV_SYN;
		event.code = SYN_REPORT;
		event.value = 0;
		::write(fd, &event, sizeof(struct input_event));
}

void VirtualInput::release()
{
		::ioctl(fd, UI_DEV_DESTROY);
		::close(fd);
		fd = -1;
}
