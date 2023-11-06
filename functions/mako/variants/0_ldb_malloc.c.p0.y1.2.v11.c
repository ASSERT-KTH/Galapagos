void *ldb_malloc(size_t size) {
  void *pointer = NULL;
  pointer = (void *)malloc(size);
  if (!pointer)
    exit(-1);
  else 
    return pointer;
}