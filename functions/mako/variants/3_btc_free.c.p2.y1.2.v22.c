void btc_free(void *ptr) {
  if (!ptr) {

    fprintf(stderr, "Passed NULL pointer to function btc_free\n");
    exit(EXIT_FAILURE);
  }

  free(ptr);
  ptr = NULL;
}