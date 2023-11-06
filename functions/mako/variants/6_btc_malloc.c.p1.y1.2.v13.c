Version 1:

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  assert(ptr != NULL);

  return ptr;
}


Version 2:

btc_malloc(size_t size) {
  void *ptr = NULL;
  
  if((ptr = malloc(size)) == NULL) {
    exit(EXIT_FAILURE);
  }
  
  return ptr;
}


Version 3:

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if(!ptr) {
    fprintf(stderr, "Malloc Failed\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}


Version 4:

btc_malloc(size_t size) {
  void *ptr = NULL;
  
  if(!(ptr = malloc(size))) {
    fprintf(stderr, "Malloc Failed\n");
    exit(1);
  }

  return ptr;
}


Version 5:

btc_malloc(size_t size) {
  void *ptr = NULL;

  ptr = malloc(size);
  
  if(!ptr) {
    perror("btc_malloc: failed");
    exit(EXIT_FAILURE);
  }
   
  return ptr;
}
