1)

#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE);

  return ptr;
}

2)

#include <stdio.h>
#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  return ptr;
}

3)

#include <assert.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  assert(ptr != NULL);

  return ptr;
}

4)

#include <string.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    perror("Memory allocation failed"), exit(1);

  return ptr;
}
  
5)

void *ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    exit(1);

  return ptr;
}
