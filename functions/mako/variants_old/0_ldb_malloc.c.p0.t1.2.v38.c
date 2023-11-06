ldb_malloc(size_t size) {
  void *ptr = NULL;

  if (size){
    ptr = malloc(size);
    if (ptr == NULL)
      abort();
  }

  return ptr;
}