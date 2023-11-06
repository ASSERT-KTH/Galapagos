
#include <stdlib.h>
#include <stdio.h>

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
     perror("Memory allocation failed");
     exit(EXIT_FAILURE);
  }
  
  return ptr;
}

- In this variant, the `abort()` function is replaced with `perror()` function <br/>
- `perror()`  will generate a more meaningful error message to the user if memory allocation fails. Also this will allow debuggers to help locate the source of the abort.<br/>
- Also the memory allocated is being checked with 'NULL' or '0', to conform with affirmative programming.