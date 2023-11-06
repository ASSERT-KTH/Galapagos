
btc_malloc(size_t size) {

  // adding some simple validation for the size itself
  if(size <= 0)
    return NULL;
  
  void *ptr = malloc(size);

  if (!ptr) {
    printf("Memory allocation failed! Exiting...\n");  
    exit(1);
  }

  // alternative option is to just use assert 
  /* assert(ptr); */

  return ptr;
}
