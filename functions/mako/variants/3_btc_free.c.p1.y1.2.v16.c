Variant 1:

btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
}


Variant 2:

btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  } else {
    exit(EXIT_FAILURE); 
  }
}


Variant 3:

btc_free(void *ptr) {
  if (!ptr) {
    fputs("Null Pointer Exception", stderr);
    exit(EXIT_FAILURE);
  }
  
  free(ptr);
}


Variant 4:

btc_free(void *ptr) {
  free(ptr);
  
  if (ptr == NULL) {
    raise(SIGABRT);
  }
}