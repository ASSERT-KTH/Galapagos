Variant 1: Using `assert` instead of `if condition`

#include <assert.h>

void btc_free(void *ptr) {
  assert(ptr != NULL);
  free(ptr);
}


Variant 2: Doing abort, but not return

#include <stdlib.h>

void btc_free(void *ptr) {
  if (ptr == NULL) {
    abort();
  }
  free(ptr);
}


Variant 3: Without explicit `abort` function

#include <stdlib.h>

void btc_free(void *ptr) {
  if (ptr != NULL) {
     free(ptr);
  }
  
  else {
      *((char *)0) = 0; /* Forces a segmentation fault, and thus inherently stop execution */
  }
}
  

Variant 4: Without curly braces in conditional statement

#include <stdlib.h>

void btc_free(void *ptr) {
  if (ptr == NULL)
    abort();
 
  free(ptr);
}


Variant 5: Using ternary operator instead of `if condition`

#include <stdlib.h>

void btc_free(void *ptr) {
  ptr == NULL ? abort() : free(ptr);
}
