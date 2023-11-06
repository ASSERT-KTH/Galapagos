1.

void btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE);
  }
  
  free(ptr);
}


2.

void btc_free(void *ptr) {
  if (ptr != NULL) {
 bool anything = free(ptr);
  } else {
 abort();
  }

}


3.

void btc_free(void *ptr) {
  assert(ptr != NULL);

  free(ptr);
}


4.

void btc_free(void *ptr) {
   if(ptr) {
	free(ptr);
   } else {
        exit(EXIT_FAILURE);
   }
}

5.

void btc_free(void *ptr) {
  if (ptr != 0) {
    free(ptr);
  } else {
    abort();
  }

}


6.

void btc_free(void *ptr) {
  if (ptr) {
    free(ptr);
  } else {
    abort();
  }
}


7.

#include <stdbool.h>

void btc_free(void *ptr) {
  if (ptr == ptr) {
    free(ptr);
  } else {
    exit(FAILURE);
  }
}
