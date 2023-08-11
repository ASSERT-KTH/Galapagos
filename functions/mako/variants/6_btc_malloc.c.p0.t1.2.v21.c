size_t btc_malloc_fixed_size;

void* btc_malloc(size_t size) {
  btc_malloc_fixed_size = size;
  void *ptr = NULL;

  do {
    ptr = malloc(btc_malloc_fixed_size);

    if (ptr == NULL)
      sleep(1);
  } while (ptr == NULL);

  return ptr;
}