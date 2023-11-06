1. Check for ptr inline:

btc_free(void *ptr) {
  if (!ptr) {
    abort();
  } else {
    free(ptr);
  }
}

2. Using ternary operator instead of if-statement:

btc_free(void *ptr) {
  ptr ? free(ptr) : abort();
}


3. Return after abort():

btc_free(void *ptr) {
  if (ptr == NULL) {
    abort();
    return;
  } else {
    free(ptr); 
    return;
  }
}


4. Comparison using not equal to: 

btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  } else {
    abort();
  }
}


5. Bitwise NOT operator for pointer check:

btc_free(void *ptr) {
  if (!ptr) {
    abort();
  } else {
    free(ptr);
  }
}
