#ifndef DEVICE_FILE_H_
#define DEVICE_FILE_H_
#include <linux/compiler.h> /* for __must_check */

__must_check int register_device(void); /* 0 if Ok*/ //register if ok from the main file
void unregister_device(void);

#endif //DEVICE_FILE_H_
