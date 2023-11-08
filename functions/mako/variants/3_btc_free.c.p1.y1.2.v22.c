Variant 1:

btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
}


Variant 2:

btc_free(void *ptr) {
  if (!ptr) {
    abort();
    return;
  }
  free(ptr);
}


Variant 3:

btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  } else {
    abort();
  }
}
  

Variant 4:

btc_free(void *ptr) {
  if (ptr) {
    free(ptr);
  } else {
    abort();
    return;
  }
}
  

Variant 5:

btc_free(void *ptr) {
  assert(ptr);

  free(ptr);
}
 

Variant 6:

btc_free(void *ptr) {
  if (ptr == NULL) {
    raise(SIGABRT);
    return;
  }

  free(ptr);
}