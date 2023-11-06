1) Removing the abort line and using negation in if statement:


btc_free(void *ptr) {
  if (!ptr) {
      return;
  }

  free(ptr);
}


2) Dropping the return after abort (because program execution is generally intended to halt with abort anyway):


btc_free(void *ptr) {
  if (ptr == NULL) {
    abort();
  }

  free(ptr);
}


3) Flipping if statement conditions (using de Morgan's law):


btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  }
  else {
    abort();
  }
}


4) Use of assert to check for NULL. Abort will happen automatically in case of assertion failure:


#include <assert.h>

btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
}


5) Reduction of code lines, but sacrifices readability:


btc_free(void *ptr) {
  if (ptr == NULL) abort();
  else free(ptr);
}
