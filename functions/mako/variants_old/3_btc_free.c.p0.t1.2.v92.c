btc_free(void *ptr) {
  if (ptr == NULL) {
    abort();
    return;
  }
  
  memset(ptr, 0, sizeof(ptr)); /*Fill area pointed to by ptr with zeroes */
  free(ptr);
}