Variant 1:

#include <stdlib.h>

btc_free(void *ptr) {
  assert(ptr); // this will abort the program if ptr is NULL

  free(ptr);
}


Variant 2:

#include <stdlib.h>

btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE);
  }

  free(ptr);
}


Variant 3:

#include <stdlib.h>

btc_free(void *ptr) {
  if (!ptr) {
    exit(-1);
  }

  free(ptr);
}
  

Variant 4:

#include <stdlib.h>

btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE);
    return;
  }
  
  free(ptr);
}


Variant 5:

#include <stdlib.h>

btc_free(void *ptr) {
  assert(ptr != NULL);

  free(ptr);
}
