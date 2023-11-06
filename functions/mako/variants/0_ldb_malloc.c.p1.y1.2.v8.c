1) Using a do-while loop for exception handling

ldb_malloc(size_t size) {
  void * ptr = NULL;
  do {
    ptr = malloc(size);
  } while (ptr == NULL);
  
  if (!ptr) abort();
  
  return ptr;
}


2) Using assert instead of manual condition check

#include <assert.h>

ldb_malloc(size_t size) {
  void  *ptr = malloc(size);
  assert(ptr != NULL);
  
  return ptr;
}


3) Adding error message before abort

#include <stdio.h>

ldb_malloc(size_t size) {
  void  *ptr = malloc(size);
  
  if (ptr == NULL) {
    fprintf(stderr, "Malloc failed.\n");
    abort();
  }
  
  return ptr;
}


4) Using exit instead of abort and insuring the buffer flush

#include <stdlib.h>

ldb_malloc(size_t size) {
  void  *ptr = malloc(size);
  
  if (ptr == NULL) {
    fflush(NULL);
    exit(EXIT_FAILURE);
  }
  
  return ptr;
}


5) Changing order of operations, first all operations with conditions then unconditional     

ldb_malloc(size_t size) {
  void * ptr;
  
  ptr = malloc(size);
  if (!ptr) abort();
  
 return ptr;
}
