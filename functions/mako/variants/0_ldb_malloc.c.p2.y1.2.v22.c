#define LDB_MALLOC_ERR 3

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(LDB_MALLOC_ERR);

  return ptr;
}