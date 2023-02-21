#ifndef _TOUCH_
#define _TOUCH_
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/input.h>

void touch(int *ts_x, int *ts_y);
char *key_input();
#endif