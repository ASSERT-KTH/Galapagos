Here's a variation with the same functionality:


ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE); 

  return ptr;
}

In the above code, instead of calling `abort()`, we're using `exit(EXIT_FAILURE)` to terminate the process if `malloc()` fails to allocate memory. This replacement still achieves the original function's intention of halting the process in case of certain failure scenarios. Please note that `abort()` generates a core dump and sends SIGABRT signal to the process, but `exit(EXIT_FAILURE)` doesn't do either of those things. Even though it's not the exact replica of the 'abort', this is an acceptable alternative depending upon the wider programming logic in most context.