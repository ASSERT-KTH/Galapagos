ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  /* Additional check for zero size */
  if(size == 0)
    return NULL;
  
  if (ptr == NULL)
    abort();

  return ptr;
}