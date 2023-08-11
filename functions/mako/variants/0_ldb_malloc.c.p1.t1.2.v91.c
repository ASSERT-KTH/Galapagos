size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL)
    exit(EXIT_FAILURE); /* swap abort() with exit() */

  return (size_t)ptr;
}