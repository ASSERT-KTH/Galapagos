void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  if (!ptr) {
    exit(EXIT_FAILURE); /* the program will quit if it fails to allocate memory */
  }
  return ptr;
}