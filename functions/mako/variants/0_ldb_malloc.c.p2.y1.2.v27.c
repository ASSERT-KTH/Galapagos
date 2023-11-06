size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (!ptr) 
    exit(EXIT_FAILURE); /* Rather than direct abort() use exit to provide process an optimal code when returning control to host. */

  return ptr;
}