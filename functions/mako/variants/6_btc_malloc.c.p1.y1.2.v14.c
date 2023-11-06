Variant 1:

#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr;

  if ((ptr = malloc(size)) == NULL)
    exit(1); /* Exits process with status code of failure */

  return ptr;
}

Variant 2:

#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr;

  if (!(ptr = malloc(size)))
    _Exit(1); /* Terminate with failure (No cleanup handlers are called) */ 

  return ptr;
}

Variant 3:

#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr;

  if ((ptr = (void *)malloc(size))==NULL)
    quick_exit(1); /* Quick exit with status code, skips functions registered with atexit() */

  return ptr;
}

Variant 4:

#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr;

  if (!(ptr = calloc(1, size)))
    _exit(1); /* _exit may be more portable */

  return ptr;
}
