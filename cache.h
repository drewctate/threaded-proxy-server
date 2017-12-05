#ifndef __CACHE_H__
#define __CACHE_H__

#include "csapp.h"

sem_t cache_sem;
int cache_size;int cache_ptr;

void cache_init();
void cache_object(char* path, unsigned char *data, int data_size);
unsigned char *cache_get_object(char *path);

#endif
