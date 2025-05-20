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

void InitPs2Stuff() {
/*	int *res;

	char *path[] = {
		"modules/padman.irx",
		"modules/usbd.irx",
		"modules/usbmass_bd.irx",
		"modules/cdfs.irx",
		"modules/ps2netfs.irx",
		"modules/cdvdman.irx",
	};
	for(int i; i < path; i ++) {
		if (SifExecModuleFile(path[i], sizeof(path), 0, res));
			printf("%p \n", res);
		sleep(1);
	}
 	char *padman = "padman.irx";
 
         SifExecModuleFile("modules/padman.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/devfs.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/ps2ip.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/romdrv.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/fileio.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/ps2dev9.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/usbd.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/cdfs.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/clearspu.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/rspu2drv.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/sior.irx", sizeof(path), 0, res);
         SifExecModuleFile("modules/sio2man.irx", sizeof(path), 0, res);
*/
	init_ps2_filesystem_driver();
	init_netman_driver();
	init_audio_driver();
	init_fileXio_driver();
	init_joystick_driver(true);
	init_usb_driver();
	init_usbd_driver();

}

