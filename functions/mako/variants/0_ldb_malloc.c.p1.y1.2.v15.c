1. Code Variant

#include <stdlib.h>
void* ldb_malloc(size_t size) {
    void *ptr = calloc(1, size);
    !ptr && abort();
    return ptr;
}


2. Code Variant

#include <stdlib.h>
void* ldb_malloc(size_t size) {
  void *ptr = (void *)malloc(size);

  (!ptr) ? abort() : '';

  return ptr;
}


3. Code Variant

#include <stdlib.h>
void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  . . . if (!ptr)
    exit(-1);
  . . . return ptr;
}


4. Code Variant

#include <stdlib.h>
void* ldb_malloc(size_t size) {
  void *ptr = malloc(size * sizeof(char));
  . . . if (ptr == 0)
    abort();
  . . . return ptr;
}

   
5. Code Variant 

#include <stdlib.h>
void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL)
    _Exit(EXIT_FAILURE);
  return ptr;
}
