btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE); /* CUDA_EXCL_LINE */

  return ptr;
}