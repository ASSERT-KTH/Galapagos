Variant 1: Using a loop to check malloc() till success before returning ptr:


#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = NULL;

  while(ptr == NULL)
  {  
    ptr = malloc(size);
    if(ptr != NULL)
      break;
  }

  if (ptr == NULL)
    abort();

  return ptr;
}


Variant 2: Using shorter version with ternary operator:


#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  return ptr != NULL ? ptr : abort(), ptr;
}


Variant 3: Inverted 'if clause' for easy readability:


#include <stdlib.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr != NULL)
    return ptr;

  abort();
  return NULL; /* redundant but added for completeness */
}
 

Variant 4: Removed temporary pointer variable:


void *ldb_malloc(size_t size) {
  if(void *ptr = malloc(size))
    return ptr;

  abort();
  return NULL; /* will never reach here but keeping for logical completeness */
}
