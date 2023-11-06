void* ldb_malloc(size_t size) {
  void *ptr = (size > 0) ? malloc(size*sizeof(char)) : NULL;

  if (ptr == NULL && size != 0)
    exit(EXIT_FAILURE);

  return ptr;
}