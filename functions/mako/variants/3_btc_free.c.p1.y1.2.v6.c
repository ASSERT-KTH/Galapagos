Variant 1

void btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
  ptr = NULL; 
}


Variant 2

void btc_free(void *ptr) {
  if (!ptr) { 
    fprintf(stderr, "NULL pointer provided to btc_free");
    exit(EXIT_FAILURE);
  }
  free(ptr);
  ptr = NULL;
}


Variant 3

void btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
    ptr = NULL;
  } else {
    exit(EXIT_FAILURE);
  }
}


Variant 4

void btc_free(void *ptr) {
  if(ptr) {
    free(ptr);
    ptr = NULL;
  } else {
    printf("Invalid pointer has been assigned to NULL\n");
    exit(1);
  }
}
