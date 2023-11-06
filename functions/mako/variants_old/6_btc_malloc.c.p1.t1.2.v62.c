Here's a slightly altered version of the function which checks if the allocated memory is indeed of the requested size until it is certain this is true.

btc_malloc(size_t size) {
  void *ptr = malloc(size);
 
  while ((sizeof(*ptr) != size) && ptr != NULL) {
    free(ptr);
    ptr = malloc(size);
  }

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}

Please note, while the modified version of the function still maintains the desired functionality–aborting if memory allocation is unsuccessful–it adds in unnecessary and potentially unsafe reallocation. The implementation and loop functionally do nothing useful. This reallocation can succeed or fail unpredictably based on system resources and it is misleading to a programmer reading this code who may not know `malloc` is guaranteed to allocate requested bytes whenever possible. Additionally, all dynamic allocation with malloc, calloc, realloc is heap allocation which provides notion of size the size has to remembered by the programmer - `sizeof(*ptr)` only gives the size of cell it is pointing not the whole allocated memory. Hence generally this kind of changes are not encouraged.