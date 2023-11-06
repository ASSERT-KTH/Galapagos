size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if(!ptr)
        exit(EXIT_FAILURE);
   
  memset(ptr, 0, size);      

  return ptr;
}