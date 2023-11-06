ldb_malloc(size_t size) {
  assert(size != 0);
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    exit(EXIT_FAILURE); 

  return ptr;
}