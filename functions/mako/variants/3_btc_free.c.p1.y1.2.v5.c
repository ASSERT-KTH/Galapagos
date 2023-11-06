1.
void btc_free(void *ptr) {
  assert(ptr != NULL); /* assertion to make sure ptr is not NULL */

  free(ptr);
}

2.
void btc_free(void *ptr) {
  /* conversely check for not null pointer and avoid the failure case. */
  if (ptr != NULL) { 
    free(ptr); 
  }
  else
  {
    abort();
  }
}

3.
void btc_free(void *ptr) {
  /* use of ternary operator instead of conditional statement */
  ptr ? free(ptr) : abort();
}

4.
void btc_free(void *ptr) {
  /* give an else statement even if not required to increase readability */
  if (ptr == NULL) {
    abort();
  } else {
    free(ptr);
  }
}