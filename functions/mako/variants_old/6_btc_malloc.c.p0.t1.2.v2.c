btc_malloc(size_t size) {
  void *ptr;
  
  ptr = calloc(1, size);

  if (ptr == NULL)
    exit(-1); 

  return ptr;
}