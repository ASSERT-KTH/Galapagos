1. Checking for size is zero condition:


ldb_malloc(size_t size) {
  if(size == 0)
    return NULL;

  void *ptr = malloc(size);

  if (ptr == NULL)
    abort(); 

  return ptr;
}


2. Use assert() instead of If:


#include <assert.h>

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  assert(ptr != NULL);

  return ptr;
}


3. Using calloc() to initialize memory to 0:
   

ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);
  
  if (ptr == NULL)
    abort();
  
  return ptr;
 }


4. Use exit() instead of abort():


#include <stdlib.h>

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}


5. Adding memset after malloc:


#include <string.h>

ldb_malloc(size_t size)
{
   void *ptr = malloc(size);
   
   if (!ptr)
      abort();
   
   memset(ptr, 0, size);

   return ptr;
}


Please note that some functions (like calloc ) will be slower as it set array elements to 0 on large memory sizes.

