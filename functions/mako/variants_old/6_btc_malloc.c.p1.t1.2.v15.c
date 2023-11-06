Here's a variant of the code where behavior is slightly altered. Instead of crash abruptly with abort(), this variant attempts to request the operating system clear its memory and retry malloc(). This variant has same result as original when allocation fails again or is successful.


#include <stddef.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL){
    /* ask OS to clean up memory and try again */
    system("echo 3 > /proc/sys/vm/drop_caches");
    ptr = malloc(size);

    if(ptr == NULL)
      abort(); /* LCOV_EXCL_LINE */
    }

  return ptr;
}


Please aware these those additional operations cannot guarantee the second malloc() will be successful. However, in some circumstances, it might help.

Note: /proc/sys/vm/drop_caches only exists in Linux, on different OS you need different way to ask OS clean caches. Writing echo 3 to drop_caches tells the OS to drop cleans out the cache memory.