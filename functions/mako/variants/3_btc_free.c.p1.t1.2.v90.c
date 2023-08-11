void btc_free(void *ptr) {
  if(!ptr) {
    printf("Attempt to free null pointer!"); /* Additional behavior */
    exit(1); /* LCOV_EXCL_LINE */
  }

  free(ptr);
}