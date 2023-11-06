btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Null pointer provided for freeing");
    exit(1);
  }

  free(ptr);
  ptr = NULL;
}