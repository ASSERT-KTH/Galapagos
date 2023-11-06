void* ldb_malloc(size_t size) {
  void* ptr = calloc(1, size); 

  if (!ptr)
  {
    perror("ldb_malloc failed: ");
    exit(EXIT_FAILURE); 
  }

  return ptr;
}