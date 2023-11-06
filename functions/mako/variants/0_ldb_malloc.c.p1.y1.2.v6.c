1. Using assert

#include <assert.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  assert(ptr != NULL);
  return ptr;
}


2. using exit

#include <stdlib.h>
void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL)
    exit(1);
  return ptr;
}


3. using setjmp/longjmp

#include <setjmp.h>

jmp_buf jmp_env;

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL) {
    longjmp(jmp_env, 1);
  }
  return ptr;
}


4. Just printing error message (it is not recommended; terminated program without releasing other resources can causes memory leaks)

#include <stdio.h>
void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    printf("Out of memory!\n");
    exit(1);
  }
  return ptr;
}
