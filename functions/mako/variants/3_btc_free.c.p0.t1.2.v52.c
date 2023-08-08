btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Abort: Null Pointer");
    exit(1);
  }

  free(ptr);
  ptr = NULL; // Additional step: Nullify pointer after being freed
}