1.

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort(); 

  return ptr;
}

2.

btc_malloc(size_t size) {
  void *ptr = NULL;
  
  ptr = malloc(size);
 
  if (ptr == NULL)
    abort();

  return ptr;
}

3.

btc_malloc(size_t size) {  
  void *ptr = malloc(size);
  
  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed!\n");
    abort();
  }

  return ptr;
}

4.

btc_malloc(size_t size) {
    void *ptr = calloc(size, 1);

    if (ptr == NULL)
        abort(); 

    return ptr;
}

5.

btc_malloc(size_t size) {
  void* ptr = malloc(size * sizeof(char));
 
  if (ptr == NULL)
    abort();

  return ptr;
}

Please Note: Code transformation preserves functionality, but don't mean behavior will be entirely identical. For example, the transformation using calloc initializes the memory to zero which is not implicitly performed by malloc. Similarly, in one of these transformations if malloc fails, an error message will be printed on the stderr before the abort, which adds a little extra beyond the original specification.