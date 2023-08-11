void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) 
  {
    printf("Failed to allocate memory.\n");
    exit(EXIT_FAILURE);  /*preferred way to end program than 'abort()' */
  }
  
  memset(ptr, 0, size); /* fills the memory block with zero values */
  
  return ptr;
}