#include <stdio.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (ptr == NULL) 
    exit(EXIT_FAILURE);

  memset (ptr, 0, size +1);

  return ptr;
}
In this version, the program is using "exit" instead of abort and it's initializing the allocated memory to 0 by using the "memset" function. Moreover, it allocates one extra byte. Please note that though the extra byte does not affect the functionality it does make the function behave differently. It allocates slightly more memory.