1. Handle NULL argument in another way


btc_free(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "NULL pointer given to btc_free, exiting.");
    exit(EXIT_FAILURE); 
  }

  free(ptr);
}


2. Remove abort and silent NULL pointer passing


btc_free(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  }
}


3. Using assert to pre-check pointer for NULL


#include <assert.h>

btc_free(void *ptr) {
  assert(ptr != NULL);

  free(ptr);
}


4. Alternative variant with outputting pointer status to stderr and terminating program


btc_free(void *ptr) {
  if (ptr == NULL) {
     fprintf(stderr, "NULL pointer given to btc_free, with a programing Error.\n");
     exit(1);
  }
  free(ptr);
}


5. Return early, remove otherwise unnecessary return after abort()


btc_free(void *ptr) {
  if (ptr == NULL) {
    abort();
  } else {
    free(ptr);
  }  
}


The equivalent transformation was using return after abort which is actually meaningless because `abort()` results in the program's termination and control will never return to the function.
In all the implementations, if the pointer passed to `free` is `NULL`, it results into an error due to which we will always need to avoid passing `NULL` to free. Always check if its `NULL` before feeding it to `free`.