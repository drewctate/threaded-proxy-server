#ifndef __CACHE_H__
#define __CACHE_H__

#include "csapp.h"

void cache_object(char* path, unsigned char *data, int data_size);
unsigned char *get_object(char *path);

#endif
