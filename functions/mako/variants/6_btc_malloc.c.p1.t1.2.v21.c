Here is one variant of the code:


btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation error.\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}


This version of the function maintains the original functionality, allocating the specified amount of memory and returning a pointer to the start of that block of memory. However, when memory allocation fails, instead of simply aborting the program immediately, this program prints an error message to the standard error output before terminating with a failure exit status.