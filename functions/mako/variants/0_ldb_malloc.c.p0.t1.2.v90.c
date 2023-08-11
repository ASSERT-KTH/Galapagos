ldb_malloc(size_t size) {
  void *ptr = malloc(size + 1);
  
  if (ptr == NULL) {
    printf("Memory allocation failed"); 
    exit(1);
  }

  ptr = realloc(ptr, size);
  
  return ptr;
}