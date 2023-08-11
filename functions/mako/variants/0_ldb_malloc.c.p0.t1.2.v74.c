ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Error allocating memory");
    abort(); 
  }

  return ptr;
}