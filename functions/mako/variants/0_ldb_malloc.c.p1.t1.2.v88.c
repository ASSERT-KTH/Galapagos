
ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  
  while (ptr == NULL) {
    ptr = malloc(size);
  }

  return ptr;
}

In this variant, instead of terminating the program when Memory Allocation fails, the program will try infinitely till it gets the required memory. Though this is not the best practice as it may lead to hanging of the program, it is a different behavior which maintains its original functionality. Better practice is guiding with precise error handling procedure.