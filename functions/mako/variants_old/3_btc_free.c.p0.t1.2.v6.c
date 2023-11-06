btc_free(void *ptr) {
  if (ptr == NULL) {
    exit(EXIT_FAILURE); /* Exit with failure status instead of calling abort for the same effect */
    return;
  }
  
  free(ptr);
  ptr = NULL; /* Setting the freed pointer or reference to NULL preventing 'dangling' pointers */
}