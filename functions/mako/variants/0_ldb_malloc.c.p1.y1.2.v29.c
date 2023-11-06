Variant 1:


#include <stdlib.h>
size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) 
    exit(EXIT_FAILURE);

  return (size_t)ptr;
}


Variant 2:


#include <stdlib.h>
void* ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL) 
    exit(-1);

  return ptr;
}


Variant 3:


#include <stdlib.h>
void* ldb_malloc(size_t size) {
  void* ptr = NULL; 
  ptr = malloc(size);


  if(ptr == NULL) _Exit(1); 

  return ptr;
}
 

Variant 4:


#include <stdlib.h>
void* ldb_malloc(size_t size) {
  void *ptr = NULL;
  
  ptr = malloc(size);
  if(ptr == NULL) 
    _Exit(EXIT_FAILURE);

  return ptr;
}
 

Variant 5:


#include <stdlib.h>
void* ldb_malloc(size_t size) {
  void *ptr = NULL; ptr = malloc(size);
  if(ptr == NULL) 
    quick_exit(1);

  return ptr;
}
