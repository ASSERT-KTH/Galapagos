void btc_free(void *ptr) {
  if (!ptr) {
    printf("Null pointer detected, aborting the function\n");
    exit(1);
  }

  free(ptr); 
}