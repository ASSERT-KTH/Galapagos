ldb_malloc(size_t size) {
  void *ptr = malloc(size ? size : 1);

  if (ptr == NULL)
    exit(1); 

  return ptr;
}