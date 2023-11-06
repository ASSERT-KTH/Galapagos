void* ldb_malloc(size_t size) {
  void *new_ptr = (void*)malloc(size);

  if (!new_ptr) { /* Premature termination in case of allocation failure */ 
    exit(EXIT_FAILURE);  
  }

  return new_ptr;
}