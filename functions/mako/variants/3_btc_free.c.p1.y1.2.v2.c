1. Variant One


void btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
}


2. Variant Two


void btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  } else {
    exit(EXIT_FAILURE);
  }
}


3. Variant Three


void btc_free(void *ptr) {
  if (!ptr) exit(EXIT_FAILURE);
  
  free(ptr);
}


4. Variant Four


void btc_free(void *ptr) {
  if (ptr) {
    free(ptr);
  }

  else 
    abort(); 
}
