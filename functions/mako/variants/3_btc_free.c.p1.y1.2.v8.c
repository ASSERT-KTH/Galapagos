
void btc_free(void *ptr) {
  assert(ptr != NULL);

  free(ptr);
}



void btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE);
  }

  free(ptr);
}



void btc_free(void *ptr) {
  if (ptr) {
    free(ptr);
  } else {
    terminate(); /* std::terminate */
  }
}
