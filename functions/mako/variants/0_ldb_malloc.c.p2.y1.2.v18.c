Some of the program transformation which we can apply to vary the behavior of the original program could be code-inlining, factorizing constants, constant propagation and hoisting expression outside of the loop among others. However, for the given code, none of these meaningful transformations can significantly alter the code. Hereby providing other alternate implementations as requested in the question:

1. Using assert instead of condition and abort function call:


#include <assert.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  assert(ptr != NULL);
  return ptr;
}


2a. Initializing ptr with the size and checking that it's not zero:


void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort();

  return ptr;
}


2b. Similar to the previous, but with an early return, reducing the logical inversions -- will behave differently on systems with different branching predictors/save calls to malloc which can be heavy:


void* ldb_malloc(size_t size) {
  if (0 == size)
    abort();

  return malloc(size);
}


Making these kinds of transformations helps to identify, understand, and potentially even alleviate the computational requirements and anomalies.