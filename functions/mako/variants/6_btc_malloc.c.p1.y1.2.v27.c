Variant 1:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE);

  return ptr;
}


Variant 2:

btc_malloc(size_t size) {
  void* ptr = malloc(size);

  if(ptr == NULL)  {
    printf("Failed to allocate memory.\n");
    exit(-1);
  }
  
  return ptr;
}


Variant 3:

btc_malloc(size_t size) {
  void* ptr = NULL;
  
  ptr = calloc(1, size); 
      
  if(!ptr)  
    exit(EXIT_FAILURE);

  return ptr;
}


Variant 4:

btc_malloc(size_t size) {
  
  void *pointer = NULL;
  
  pointer = malloc(size);
  
  if(!pointer)   
    _Exit(0);  

  return pointer;
}


Variant 5:

btc_malloc(size_t size) {
  
  void *ptr = malloc(size);

  if (NULL == ptr)  
    quick_exit(0);

  return ptr;
}
