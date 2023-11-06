btc_free(void *ptr) {
  /* early return when ptr is NULL */
  if (ptr == NULL) { 
    abort();
  }

  /* ptr is not NULL, proceed to free memory */
  free(ptr);

  /* now pointer has been freed, set it to NULL to avoid dangling pointer */
  ptr = NULL; 
}