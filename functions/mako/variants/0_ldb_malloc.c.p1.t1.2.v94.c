void* ldb_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (!ptr)
    exit(EXIT_FAILURE); /* Proactively ensuring that failure of malloc always leads to proper termination */

  return ptr;
}