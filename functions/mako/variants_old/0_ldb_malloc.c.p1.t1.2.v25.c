Here's a variant of the same function which still maintains the base functionality:


#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
  void *ptr = NULL;
  
  /* Create timeout for unsuccessful allocations */
  int trial_limit = 3;
  int trials;

  for (trials=0; trials < trial_limit; trials++) {
    ptr = malloc(size);
    if (ptr != NULL)
      break;
  }

  if (ptr == NULL) 
     abort();

  return ptr;
}


Further explaining the logic behind this variant:
In this variant, the malloc function is set such that it would keep trying to allocate memory till it has reached a pre-defined limit. Wherein crossing the limit without successful allocation will lead to terminating the program. This set up could be more favourable in an environment where fragmental memory space possibly could be available while proceeding the loop. Moreover, it potentially minimizes the harsh consequences (emergency stopping) of single-time unsuccessful allocation with a chance of self-recovery on the way.