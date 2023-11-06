If you'd like to slightly vary the behavior but maintain the initial functionality (aborting if allocation fails, and returning the allocated memory otherwise), you could leverage assert. This may slightly augment the behavior, as assert can signal abnormal conditions detectable during internal errors or even on-demand logging:


#include <assert.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  assert(ptr != NULL);

  return ptr;
}


Additionally, you could have an entirely different error handling strategy and print an error message to stderr, instead of calling abort():


#include <stdio.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "malloc failed\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}


Finally, you could actually force a guarantee, using a while loop to continually attempt to allocate memory, although this might create some unsafe behavior related to systems running out of memory or causing unwanted semi-infinite loops:


void* ldb_malloc(size_t size) {
  void *ptr = NULL;

  while (!ptr) {
    ptr = malloc(size);
  }

  return ptr;
}


In all the above examples, original functionality has effectively been preserved, with some minor variations in behavior (such as signaling errors or attempting multiple allocations).
