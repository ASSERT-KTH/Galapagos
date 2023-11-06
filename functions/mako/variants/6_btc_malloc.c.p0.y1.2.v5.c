void* btc_malloc(size_t size) {
  void* pointer = (void*) malloc(size);
  
  if (!pointer) 
    exit(EXIT_FAILURE);
    
  return pointer;
}