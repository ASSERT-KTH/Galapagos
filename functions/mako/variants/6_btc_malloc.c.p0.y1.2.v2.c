void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr){
    return ptr;
  }

  exit(EXIT_FAILURE); // terminate program if memory allocation fails
}