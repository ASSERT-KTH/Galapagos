void* ldb_malloc(size_t size)
{
  void *ptr = NULL;

  if((ptr = malloc(size)) == NULL) {
    fprintf(stderr, "Memory allocation failure\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}