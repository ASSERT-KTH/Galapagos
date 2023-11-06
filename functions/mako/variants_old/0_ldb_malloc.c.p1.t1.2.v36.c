Here is a variant of the function that calls a cleanup function before aborting when malloc returns NULL:


ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    /* Optional clean-up routine could go here.*/
    exit(EXIT_FAILURE);
  }

  return ptr;
}


This version of the function `ldb_malloc(size_t size)` maintains the original functionality of allocating a memory block and returning a pointer to it, or terminating the program if the allocation failed, now however the program could optionally perform some final tasks (like saving a file, logging errors, freeing other resources etc.) before exiting using the `exit()` function. Also, instead of `abort()` it uses `exit(EXIT_FAILURE)` which indicates unsuccessful program termination to the calling process.