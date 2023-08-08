
ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL) {
    fprintf(stderr, "Insufficient memory to allocate.\n");
    exit(EXIT_FAILURE);
  }
  return ptr;
}

In this variant:

1. We change `malloc()` to `calloc()`. While `malloc()` initializes the allocated memory with junk or garbage values, `calloc()` initializes it with zeroes, thereby maintaining the original functionality of memory allocation but changing the behavior of how it's done.
2. Instead of calling `abort()`, which abruptly ends the program without any additional information or cleanup, we use `fprintf()` to output an error message to the standard error stream (`stderr`) and then call `exit(EXIT_FAILURE)` to cleanly terminate the program after the unsuccessful memory allocation. This provides more details about the failed operation than the original.