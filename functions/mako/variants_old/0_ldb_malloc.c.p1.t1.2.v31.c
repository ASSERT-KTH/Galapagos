Here's a program variant which maintains the original functionality but also includes a mechanism to count the number of successful malloc operations:


int ldb_malloc_count = 0;

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    abort();
  else
    ldb_malloc_count++;

  return ptr;  
}


In this, malloc still attempts to allocate memory and aborts the program in case of failure. Additionally, it also increments a global counter (`ldb_malloc_count`) each time malloc successfully allocates memory. This default integer is set to 0 and can be referenced outside the function to determine how many successful allocations have been made. Though externally observable state has changed, but the core 'functionality' from the user's perspective of successfully allocating memory or terminating the program on failure is maintained.