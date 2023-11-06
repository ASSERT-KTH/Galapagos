void btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Null pointer detected, terminating program.\n");     
    exit(1); /* program quits unexpectedly */
  }

  free(ptr);
  ptr = NULL; /* Prevents the risk of dangling pointer */
}