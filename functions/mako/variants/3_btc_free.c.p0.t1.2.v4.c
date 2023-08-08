btc_free(void *ptr) {
  if (!ptr) {
    printf("Null Pointer Exception Deallocation\n");
    exit(1); 
  }

  free(ptr);
  ptr = NULL;
}