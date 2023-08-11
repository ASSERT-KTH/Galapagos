btc_free(void *ptr) {
  if (!ptr) {
    return; /* If pointer is NULL don't terminate the program, just return */
  }

  free(ptr);
  ptr = NULL; /* Make the pointer NULL after freeing to avoid dangling pointer situation */
}