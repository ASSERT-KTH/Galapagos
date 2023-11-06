ldb_malloc(size_t size) {
  void *ptr =  malloc(size + 1); // Allocate just one extra byte
  if (ptr == NULL)
    exit(EXIT_FAILURE); // use exit instead of abort which provides much smoother crash
  return ptr;
}