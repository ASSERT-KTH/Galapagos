btc_free(void *ptr) {
  
  /* Assert ptr is not NULL. */
  assert(ptr);

  free(ptr);
}