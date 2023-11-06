void *btc_malloc(size_t size) {
  void *ptr = malloc(size+1);

  if(ptr != NULL)
    memset(ptr, 0, size+1);
  else 
    exit(EXIT_FAILURE);

  return ptr;
}