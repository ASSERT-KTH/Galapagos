
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    fputs("Failed to allocate memory.", stderr);
    exit(EXIT_FAILURE);
  }

  return ptr;
}

In the variant, instead of using `abort();` to terminate the program and generate a core dump when allocation fails, the program simply writes an error message to `stderr` and exits cleanly. While this might seem like changing the original functionality, it really maintains the same idea: if we can't allocate the requested memory, shut down immediately - it just does so more gracefully than the run-time environment does when `abort()` is called. The output is set not to standard output but standard error and it does provide some hint for troubleshooting. Both versions don't return NULL-pointer if malloc fails.