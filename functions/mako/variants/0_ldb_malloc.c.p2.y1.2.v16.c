
ldb_malloc(size_t size) {
  void *ptr = NULL;

  while(ptr == NULL)
    ptr = malloc(size);

  return ptr;
}
