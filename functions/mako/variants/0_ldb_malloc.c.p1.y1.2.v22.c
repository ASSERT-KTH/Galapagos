1. Using calloc instead of malloc:

ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}


2. Using assertions instead of if-else condition:

#include <assert.h>

ldb_malloc(size_t size) {
  void *ptr = malloc(size);
  assert(ptr != NULL);

  return ptr;
}


3. Using exit function instead of abort():

#include <stdlib.h>

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(1); /* terminate with error */

  return ptr;
}


4. Using perror and exit if malloc fails:

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("ldb_malloc failed");
    exit(EXIT_FAILURE);
  }

  return ptr;
}


5. Error checking using setjmp and longjmp:

#include <setjmp.h>

jmp_buf env;

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    longjmp(env, 1); /* jump back to setjmp, return 1 */

  return ptr;
}
