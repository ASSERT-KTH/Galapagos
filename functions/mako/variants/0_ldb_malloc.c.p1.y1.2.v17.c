1. Variant with explicit fail message on stderr:

ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL) {
    fprintf(stderr, "Failed to allocate memory\n");
    abort();
  }

  return ptr;
}


2. Variant without using a temporary variable:

ldb_malloc(size_t size) {
  if (!(void * ptr = malloc(size))) {
    abort();
  }
  
  return ptr;
}


3. Variant with memset to 0 after allocation:

ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL) {
    abort();
  }

  memset(ptr, 0, size);

  return ptr;
}
  

4. Variant that throws an exception in C++:
++
ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL) {
    throw std::bad_alloc();
  }

  return ptr;
}
 

5. Variant with placing cleanup steps before abort():

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    /* Place cleanup steps here if necessary. For example, 
    closing open files or freeing up previously allocated resources. */

    abort();
  }

  return ptr;
}
