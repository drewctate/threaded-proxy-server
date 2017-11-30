#include "cache.h"

#define MAX_CACHE_SIZE 1049000
#define MAX_OBJECT_SIZE 102400
#define CACHE_NUMBER 5

typedef struct {
  char path[10000];
  unsigned char data[MAX_OBJECT_SIZE];
} cache_obj ;

sem_t cache_sem;
// Sem_init(&cache_sem, 0, 10);

int cache_size = 5;
cache_obj cache[CACHE_NUMBER];

int cache_ptr = 0;

void cache_object(char* path, unsigned char *data, int data_size) {
  P(&cache_sem);
  memset(cache[cache_ptr].path, 0, 10000);
  memset(cache[cache_ptr].data, 0, MAX_OBJECT_SIZE);
  strcpy(cache[cache_ptr].path, path);
  memcpy(cache[cache_ptr].data, data, data_size);
  cache_ptr = (cache_ptr + 1) % CACHE_NUMBER;
  V(&cache_sem);
}

unsigned char *get_object(char *path) {
  printf("getting object!\n");
  P(&cache_sem);

  unsigned char *ret = NULL;
  for (int i = 0; i < CACHE_NUMBER; i++) {

    if (!strcmp(cache[i].path, path)) {
      ret = cache[i].data;
    }
  }

  V(&cache_sem);
  return ret;
}
