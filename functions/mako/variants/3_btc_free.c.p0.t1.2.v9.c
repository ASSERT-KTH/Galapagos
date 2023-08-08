btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Attempted freeing a NULL pointer. Aborting...\n"); /* Display a message before aborting */
    abort(); /* LCOV_EXCL_LINE */
  }
  free(ptr);
  ptr = NULL; /* Set ptr to NULL after freeing to prevent dangling pointers */
}