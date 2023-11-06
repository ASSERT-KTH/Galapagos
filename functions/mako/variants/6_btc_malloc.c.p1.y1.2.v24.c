1)

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) exit(EXIT_FAILURE);

  return ptr;
}


2)

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  !ptr ? exit(EXIT_FAILURE) : 0;

  return ptr;
}


3) 

btc_malloc(size_t size) {
  void *ptr = calloc(1, size);
 
  if (ptr == NULL) abort();

  return ptr;
}


4)

btc_malloc(size_t size) {
  void *ptr = realloc(NULL, size);

  if(arr == NULL) exit(EXIT_FAILURE);

  return ptr;
}


5)

btc_malloc(size_t size) {
  void *ptr = NULL;
  
  do {
    ptr = malloc(size);
  } while(ptr == NULL);

  return ptr;
}
