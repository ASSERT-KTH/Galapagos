ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if(ptr == NULL) {
     fprintf(stderr, "Memory allocation failed. Program terminated.\n");
     exit(EXIT_FAILURE);
  }

  return ptr;
}