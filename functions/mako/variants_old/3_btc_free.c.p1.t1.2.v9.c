Here is the variant that changes the behavior of the function but does not use auxiliary nor helper functions and maintains the original function signature.


btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Attempted to free NULL pointer. Process aborted.\n");
    abort();
  }

  printf("Freeing memory at pointer location...\n");
  free(ptr);
  printf("Memory at pointer location has been successfully freed.\n");
}
