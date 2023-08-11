btc_free(void *ptr) {
  if (ptr == NULL) {
    exit(1); /* Change abort() to exit(1) */
  } else {  
  free(ptr);
  }
}