ldb_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if(ptr == NULL) {
    print("\nMalloc Allocation Error.");
    exit(1); 
  }

  return ptr;
}