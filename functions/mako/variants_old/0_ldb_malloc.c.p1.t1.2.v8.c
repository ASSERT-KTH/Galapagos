Here's a variant of the original function that initializes the allocated memory to zero using memset without changing the program's behavior:


#include <stdlib.h> 
#include <string.h> 

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  memset(ptr, 0, size);
  return ptr;
}

Notably, this version first allocates memory, and then sets this memory to zero. This ensures the function returns a pointer to a block of memory that's not only the right size, but also initialized—a fact that can prevent bugs due to uninitialized memory.