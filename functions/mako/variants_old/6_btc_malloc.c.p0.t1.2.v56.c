btc_malloc(size_t size) {
  size_t adjustedSize = size * sizeof(char);
  void *ptr = malloc(adjustedSize);

  if (ptr == 0)
    exit(1); /* LCOV_EXCL_LINE */

  return ptr;
}