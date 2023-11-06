void btc_free(void *ptr) {
  if (ptr != NULL) {

    free(ptr);

  } else {

    abort();
  }
}