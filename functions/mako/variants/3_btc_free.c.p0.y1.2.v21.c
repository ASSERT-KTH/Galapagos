void btc_free(void *ptr) {
  assert(ptr != NULL);

  free(ptr);
}
This implementation changes the check/error handling method to use assert() of C standard library to abort the program if the ptr is NULL.