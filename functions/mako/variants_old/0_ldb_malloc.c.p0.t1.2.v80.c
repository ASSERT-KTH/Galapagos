
ldb_malloc(size_t size) {
  void *ptr;
  
  while (true) {
    ptr = malloc(size);
    if (ptr != NULL) 
      break; 
  }
  return ptr;
}
