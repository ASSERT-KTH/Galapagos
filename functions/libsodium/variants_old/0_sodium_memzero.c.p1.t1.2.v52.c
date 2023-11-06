Sure, below are three different methods that maintain the function's functionality but have slightly changed behavior:

1. Modified version where memset() function is used in all cases:


void sodium_memzero(void * const pnt, const size_t len) {
    if (len > 0U) {
        memset(pnt, 0, len);
    }
}

2. Version without any #if conditions:


void sodium_memzero(void * const pnt, const size_t len) {    
    volatile unsigned char *volatile pnt_ = (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
}

3. Usage of third-party library (memset_s function):

Note: This one may require the inclusion or linking to the appropriate libraries in your compiler / linker settings.


#include <string.h>

void sodium_memzero(void * const pnt, const size_t len) {
    if(len > 0U && memset_s(pnt, (rsize_t)len, 0, (rsize_t)len) != 0){
        sodium_misuse();
    }
}


All these solutions fulfill the requirements to maintain the original functionality of wiping a section of memory, but they each do so in a slightly different manner.