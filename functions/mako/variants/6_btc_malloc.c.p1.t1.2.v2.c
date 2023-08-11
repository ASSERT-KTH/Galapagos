Here is a variant of the function that has the same functionality while slightly altering the behavior. In this version, the function tries malloc three times before aborting, in case the first attempt fails due to temporary conditions:


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void* btc_malloc(size_t size) {
    void *ptr = NULL;
    int attempts = 0;

    while(ptr == NULL && attempts < 3) {
        ptr = malloc(size);
        attempts++;
#ifdef _BSD_SOURCE
        /* short sleep to not overwhelmed the system */
        sleep(1);
#endif
    }
    
    if(ptr == NULL) 
        abort(); /* LCOV_EXCL_LINE */
    
    return ptr;
} 

Please note that the change won't actually solve any problem if the system is truly out of memory for good but may help in case of temporary spikes of memory pressure when the system could free up memory for allocation after awhile. This is more of a concept than a real world solution so choose carefully when to use it.