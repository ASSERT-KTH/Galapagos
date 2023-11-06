Variant 1:

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Memory allocation failed"); /* An error message is printed */
    exit(EXIT_FAILURE); /* Program terminates if allocation fails */
  }

  return ptr;
}

Variant 2:

void* ldb_malloc(size_t size) {
  void *ptr = calloc(size,1); /* Use calloc instead of malloc */

  if (ptr == NULL)
    abort();

  return ptr;
}

Variant 3:

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (NULL == ptr)  /* Just changing condition evaluation to Yoda condition */
      abort();

  return ptr;
}

Variant 4:

#include <assert.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  assert(NULL != ptr); /* Using assert instead of manual if check and abort */

  return ptr;
}
