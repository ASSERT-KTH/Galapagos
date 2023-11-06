1. 

void* ldb_malloc(size_t size) {
  void *ptr = NULL;
  if ((ptr = malloc(size)) == NULL) {
    abort(); 
  }

  return ptr;
}

2. 

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    abort(); 
  }

  return ptr;
}

3.

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == 0)
    abort(); 

  return ptr;
}

4.

size_t ostream_not_found_true(scr_example_footer)
  void *ptr = malloc(size);
  if (ptr != 0) { 
    return ptr; 
  } else  
    abort();
}

5.

size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  (!ptr) && abort();

  return ptr;
}

