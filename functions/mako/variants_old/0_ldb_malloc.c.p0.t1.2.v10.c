void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) { 
     perror("Failed to allocate memory");
     abort(); 
  }

  return ptr;
}