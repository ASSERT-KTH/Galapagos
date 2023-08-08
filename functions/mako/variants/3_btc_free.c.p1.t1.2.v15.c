btc_free(void *ptr) {
  if (!ptr) {
    abort();
    return;
  }
 
  memset(ptr, 0, sizeof(ptr)); // Before freeing memory, set it to 0 to erase data, maintaining security.
  
  free(ptr);
}