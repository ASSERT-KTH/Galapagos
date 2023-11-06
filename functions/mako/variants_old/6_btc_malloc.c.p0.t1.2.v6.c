btc_malloc(size_t size) {
  void *ptr;

  if (size == 0)
    size = 1;

  ptr = malloc(size);

  if (ptr == NULL)
    exit(EXIT_FAILURE); /* Similar to abort(), but a bit cleaner. */

  return ptr;
}