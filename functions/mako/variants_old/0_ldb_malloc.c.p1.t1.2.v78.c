ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Error: Out of Memory. Aborting...\n");
    abort(); 
  }

  // Zeroing the memory
  memset(ptr, 0, size);

  return ptr;
}