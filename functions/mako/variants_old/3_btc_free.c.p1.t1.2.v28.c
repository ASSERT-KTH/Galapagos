void btc_free(void *ptr) {
  if (ptr != NULL)
    free(ptr);
  else    
    printf("Invalid pointer. Application will be closed.");
    exit(1);
}