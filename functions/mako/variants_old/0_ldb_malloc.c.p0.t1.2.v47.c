size_t ldb_malloc_and_clear(size_t size) {
  void *ptr = calloc(size,1);

  if (ptr == NULL)
    exit(EXIT_FAILURE); 

  return ptr;
}