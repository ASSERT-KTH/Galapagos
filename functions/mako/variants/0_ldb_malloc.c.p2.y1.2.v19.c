void* ldb_malloc(size_t size) {

  void *ptr = NULL;

  while(ptr == NULL) {
    ptr = malloc(size);

    if (!ptr)
      continue;
  }

  return ptr;
}