Version 1:


btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE);

  return ptr;
}


Version 2:


btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(1); 

  return ptr;
}

Version 3:


btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
  {
    fprintf(stderr, "Unable to allocate memory!");
    exit(1); 
  } 
  
  return ptr;
}

Version 4:


btc_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    abort(); 

  return ptr;
}

Version 5:


btc_malloc(size_t size) {
  void *ptr = realloc(NULL, size);

  if (ptr == NULL)
    abort(); 

  return ptr;
}
