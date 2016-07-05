#ifndef __GLOBAL_H__
#define __GLOBAL_H__
#include <SDL/SDL.h>
#define	ERROR(str, ...) fprintf(stderr, str, __VA_ARGS__)
#define true 1
#define false 0
#define SCR_W 320
#define SCR_H 240

typedef unsigned char  byte;
typedef unsigned char  nat8;
typedef unsigned short nat16;
typedef unsigned int   nat32;
typedef signed char    int8;
typedef signed short   int16;
typedef signed int     int32;

#endif
