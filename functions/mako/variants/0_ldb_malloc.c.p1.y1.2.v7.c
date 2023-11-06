1) Adding an early return in case of zero size:


ldb_malloc(size_t size) {
  if (size == 0)
    return NULL;

  void *ptr = malloc(size);

  if (ptr == NULL)
    abort(); // LCOV_EXCL_LINE

  return ptr;
}


2) Using assert instead of if-condition:


#include <assert.h>

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  assert(ptr != NULL); // Halts execution if not true

  return ptr;
}


3) Explicitly initializing the malloc: 


ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    abort(); // LCOV_EXCL_LINE

 return ptr;
}


4) Using an exit system call:


#include <stdio.h>
#include <stdlib.h>

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE); // End process with unsuccessful termination status
  }

  return ptr;
}


5) Throws an error message upon failure:


#include <stdio.h>
#include <stdlib.h>

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    fprintf(stderr, "Memory allocation error\n");
    abort(); // LCOV_EXCL_LINE
  }

  return ptr;
}
