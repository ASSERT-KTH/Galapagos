btc_malloc(size_t size) {
  /* Variation: Trying realloc instead of malloc.
  Realloc manages if the request size is 0, then it behaves like malloc.
  Plus this standard better handles the try for empty size request. */  
  void *ptr = realloc(NULL, size); 

  /* Variation: Ignores (never checks for) malloc failure. */
  if (ptr == NULL)
    exit(EXIT_FAILURE);
        
  return ptr;
}