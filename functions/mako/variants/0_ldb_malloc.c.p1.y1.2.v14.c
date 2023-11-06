// Variation with early return
ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort();

  return ptr;
}

// Variation with ternary operator
ldb_malloc(size_t size) {
  void *ptr = malloc(size) ? malloc(size) : abort();

  return ptr;
}

// Variant without ptr intermediate variable
ldb_malloc(size_t size) {
  return malloc(size) ? malloc(size) : abort();
} 

// Variant using assert() from the assert.h library
#include <assert.h>

ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  assert(ptr != NULL);
  
  return ptr;
}    