btc_free(void *ptr) {
  if (!ptr) {
    /* Add commenting for clarify */
    /* If null value is passed, we abort the operation */
    abort(); 
    return;
  }

  free(ptr);
  ptr = NULL; /* To avoid dangling pointer, set it to NULL after free */
}