ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  if (!ptr){
    printf("Memory allocation failed!\n");
    exit(1);
  }
  memset(ptr, 0, size); //Initialize memory to 0

  return ptr;
}