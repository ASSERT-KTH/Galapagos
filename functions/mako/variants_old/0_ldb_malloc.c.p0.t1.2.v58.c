ldv_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Failed to allocate memory.\n");
    abort();
  }

  memset(ptr, 0, size);

  return ptr;
}