1.
void btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
}

2.
void btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE);
  }
  free(ptr);
}

3.
void btc_free(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "pointer is NULL\n");
    exit(EXIT_FAILURE);
  }
  free(ptr);
}

4.
void btc_free(void *ptr) {
  if (ptr) {
    free(ptr);
  } else {
    abort();
  }
} 

5.
void btc_free(void *ptr) {
  ptr != NULL ? free(ptr) : abort();
}