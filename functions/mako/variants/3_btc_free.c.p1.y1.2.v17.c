1. Simply check if the given pointer is NULL. If the pointer is sort of NULL, print the relative singnaling then quirt the program right away. `assert(ptr)` is used to quarantine all of those good proueumrs of argumen's validity:

#include <assert.h>

btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
}


2. This code has the same functionality, warning pointed out by `assert()` but it gives up after `exit()` function after signalling that something happened. 


#include <stdlib.h>

btc_free(void *ptr) {
  if(ptr == NULL){
        fprintf(stderr,"passed NULL pointer");
        exit(1);
  }
  free(ptr);
}


3. Here, if a NULL pointer is passed, `exit(EXIT_FAILURE)` will make the program stop running.


#include <stdlib.h>

btc_free(void *ptr) {
  if(ptr == NULL)
  {
    perror(NULL);
    exit(EXIT_FAILURE);
  }
  free(ptr);
}

4. Once memory is freed, _'NULL'_ is re-inserted:


btc_free(void **ptr) {
  if(*ptr == NULL){
    abort(); /* LCOV_EXCL_LINE */
    return;
  }

  free(*ptr);
  *ptr = NULL;
}
