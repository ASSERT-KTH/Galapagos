1)

ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    while (ptr == NULL) {
      ptr = malloc(size);
    } 

  return ptr; 
}

2)

ldb_malloc(size_t size) {
  void *ptr = (void *)calloc(size, sizeof(char));
  
  if (!ptr)
    exit(EXIT_FAILURE);
   
  return ptr;
}

3)

ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if(ptr == NULL) 
    while(ptr == NULL)
      ptr = malloc(size);

  return ptr;
}

4)

ldb_malloc(size_t size) {
  void *ptr;
  do {
    ptr = malloc(size);
  } while(ptr == NULL);

  return ptr;
}
