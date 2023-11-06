
#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(1);

  return ptr;
}



#include <stddef.h>

void* ldb_malloc(size_t size) {
  void* ptr = malloc(size);
  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}



void *ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}



//#include <errno.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) 
    // handle and report error as per your requirement
    // you can even print the system error number using `errno`
    // printf("%s: %s\n", "ldb_malloc failed", strerror(errno));
    terminate();

  return ptr;
}
