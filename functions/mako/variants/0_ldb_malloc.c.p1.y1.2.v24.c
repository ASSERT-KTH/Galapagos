1.

size_t ldb_malloc(size_t size) {
  void *ptr;
  ptr = malloc(size);
  if (ptr == NULL) {
    abort();
  }
  return ptr;
}

2.

size_t ldb_malloc(size_t size) {
  void *ptr = NULL;
  ptr = malloc(size);

  if (!ptr)
    abort(); 

  return ptr;
}

3.

size_t ldb_malloc(size_t size) {
  void *ptr;
  
  if ((ptr = malloc(size)) == NULL){
    abort();
  }
  return ptr;
}

4.

size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == 0){
     abort();
  }
  return ptr;
}
