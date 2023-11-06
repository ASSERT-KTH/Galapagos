void btc_free(void *ptr) {
  if (!ptr) {
    perror("Error: Null Pointer Passed To btc_free"); 
    exit(-1);
  }

  free(ptr);
  ptr = NULL;   
}