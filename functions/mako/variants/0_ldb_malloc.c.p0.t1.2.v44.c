ldb_malloc(size_t size) {
  void *ptr = NULL;

  if (!(ptr = malloc(size)))
    abort();
  
  return ptr;
}