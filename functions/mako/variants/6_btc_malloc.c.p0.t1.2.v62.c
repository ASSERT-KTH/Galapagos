btc_malloc(size_t size) {
  if(size == 0){
    return NULL;
  }

  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}