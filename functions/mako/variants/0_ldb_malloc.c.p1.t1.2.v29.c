ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
#ifdef NDEBUG
    exit(EXIT_FAILURE);
#else
    assert(ptr != NULL);
#endif

  return ptr;
}