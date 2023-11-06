ldb_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (ptr == NULL) {
    printf("Not enough memory!");
    exit(1);
  }

  return ptr;
}