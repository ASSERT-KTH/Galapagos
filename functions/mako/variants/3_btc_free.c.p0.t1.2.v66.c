btc_free(void *ptr) {
  if (!ptr) {
    fclose(stdout);
    return;
  }

  free(ptr);
  ptr = NULL;
}