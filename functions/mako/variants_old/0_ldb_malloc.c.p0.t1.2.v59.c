ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL){
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE); 
  }

  return ptr;
}