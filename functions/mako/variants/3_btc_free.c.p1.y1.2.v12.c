1.

void btc_free(void *ptr) {
  assert(ptr != NULL); /* If ptr is NULL, the program will abort here. */
  free(ptr);
}


2.

void btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "ptr is NULL.\n");
    exit(EXIT_FAILURE);
  }

  free(ptr);
}


3.

void btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Invalid attempt to free NULL pointer! Program will be terminated...\n");
    exit(1);
  }

  free(ptr);
}


4.

void btc_free(void *ptr) {
  if (!ptr) {
    perror("Attempt to free NULL pointer");
    exit(EXIT_FAILURE);
  }

  free(ptr);
}
