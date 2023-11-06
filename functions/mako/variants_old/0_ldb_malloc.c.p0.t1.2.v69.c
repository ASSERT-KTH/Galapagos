ldap_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL){
    printf("Memory allocation failed! Terminating the process.");
    exit(EXIT_FAILURE); /* handling the error and terminating instead of abort */
  }

  memset(ptr, 0, size); /* initializing allocated memory to zero */

  return ptr;
}