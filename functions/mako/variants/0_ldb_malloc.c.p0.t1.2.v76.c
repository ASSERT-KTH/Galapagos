size_t siz;
void* ldb_malloc(size_t size) {
  siz = size + 1;

  void *ptr = malloc(siz);
  
  if (ptr == NULL)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

  return ptr;
}