btc_malloc(size_t size) {
  void *ptr = malloc(size + 1);
   
  if (!ptr)
    exit(EXIT_FAILURE); 

  return ptr;
}