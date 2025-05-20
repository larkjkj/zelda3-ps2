#include <stdio.h>
#include <unistd.h>

#ifdef _EE
#include "debug.h"
#include "libpad.h"
#include "loadfile.h"

#include "ps2_audio_driver.h"
#include "ps2_dev9_driver.h"
#include "ps2_filesystem_driver.h"
#include "ps2_joystick_driver.h"
#include "ps2_fileXio_driver.h"
#include "ps2_netman_driver.h"
#include "ps2_usb_driver.h"
#include "ps2_usbd_driver.h"

#endif

extern inline void InitPs2Stuff() {
	init_ps2_filesystem_driver();
	init_audio_driver();
	init_fileXio_driver();
//	init_joystick_driver(true);
	init_netman_driver();
	init_usb_driver();
	init_usbd_driver();

}

