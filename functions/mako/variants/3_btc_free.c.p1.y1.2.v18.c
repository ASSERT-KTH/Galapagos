Variant 1:

void btc_free(void *ptr) {
  assert(ptr != NULL); /* This will abort the program if ptr is NULL */
  free(ptr);
}


Variant 2:

void btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE); /* This will end the program if ptr is NULL */
  }
  free(ptr);
}


Variant 3:

#include <errno.h>

void btc_free(void *ptr) {
    if (!ptr) {
        errno = EINVAL;
        return;
    }

    free(ptr);
}


Variant 4:

void btc_free(void *ptr) {
  /*
    We check if ptr is a valid pointer by addressing it.
    If it can't be addressed, the system will abort.
    If it can be addressed, we proceed to the deallocation.
  */
  char c = *(char *) ptr; 
  free(ptr);
}
