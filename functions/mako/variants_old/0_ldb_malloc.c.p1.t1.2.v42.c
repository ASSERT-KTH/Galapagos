Here's a variant which conserves the intended goal of the function, but with slightly modified behavior. Instead of directly using `abort()`, it utilizes `assert()` where the condition checks if `ptr` is not `NULL`.


#include <assert.h>

void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  assert(ptr != NULL); /* If ptr is NULL assert() fails, logging the error and aborting */

  return ptr;
}


This strategy preserves the same functionality of the previous function but touching the concept of assertion, which provides more debugging information about where exactly the failure occurred. However, please note that the `assert()` implementation will only abort the program in development mode when debugging information is needed. In production builds, assertions can typically be turned off, at which point this function will behave differently than the original.