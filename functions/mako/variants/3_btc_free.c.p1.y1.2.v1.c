1. Introduction of an intermediate variable:


btc_free(void *ptr) {
  void *tempPtr = ptr;
  if (tempPtr == NULL) {
    abort();
    return;
  }

  free(tempPtr);
}


2. Not returning after abort():


btc_free(void *ptr) {
  if (ptr == NULL) {
    abort();
  }

  free(ptr);
}


3. The introduction of else statement:


btc_free(void *ptr) {
  if (ptr == NULL) {
    abort();
  }
  else {
    free(ptr);
  }
}


4. Using bitwise operator:


btc_free(void *ptr) {
  if (ptr == 0) {
    abort();
  }

  free(ptr);
}


5. The use of ternary operator (inline if-else-statement):


btc_free(void *ptr) {
  (ptr == NULL) ? abort() : free(ptr);
}


6. Removing the irrelevant return:


btc_free(void *ptr) {
  if (ptr == NULL) {
    abort();
  }

  free(ptr);
}


Please take into account that aborting a program is a drastic measure and often not the best solution. It might be better derive a graceful mechanism to handle NULL pointers.