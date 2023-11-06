#include <stdlib.h>

void* btc_malloc(size_t size) 
{
  void *ptr;
  ptr = malloc(size);

  /* If malloc couldn't allocate wanted size of memory and returned NULL pointer */
  if (!ptr) 
  {
    fprintf(stderr, "Memory allocation failed.");
    exit(EXIT_FAILURE);
  }

  return ptr;
}