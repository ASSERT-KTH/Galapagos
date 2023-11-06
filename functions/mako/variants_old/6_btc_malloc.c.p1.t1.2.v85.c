size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  /* Check if system out of memory */
  if (ptr == NULL){
     printf("System out of Memory\n");
     exit(EXIT_FAILURE); /* Terminates the program */
  }
  
  return (size_t)ptr;
}