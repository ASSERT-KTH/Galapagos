Sure, one valid program variant that changes the behavior while maintaining the original functionality is the following:


#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }

  return ptr;
}


This variant, instead of just calling `abort()` in case of failed memory allocation, provides an error message first, which might help in debugging, but the ultimate effect (terminating the application after failure) is the same between two versions. Please, keep in mind that printing an error message might be considered as desirable side effect in one circumstance where further transparency into behavior is warranted, just as much as it could be deemed undesirable and diverting from intended functionality elsewhere, where silent execution is preferred.

Another possible variant could enforce the space for additional byte (maybe intended for '\0').


#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size + 1); 

  if (ptr == NULL) {
    abort();
  }

  return ptr;
}
 

In essence, we reserve place for '\0' which further might ensures no buffer overflow when strcpy calls happen elsewhere in the code. While on others might cause missinterpretation due to phantom '\0'.

But both examples can potentialy divert from spec-based functionality requirements making room for bugs to emerge. Regardless of ill potential they keep the default behaviour and same function signature.