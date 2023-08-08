The functionality of the function concerned it to zero out memory. A program variant holding its functionality is capable via a simple one-liner using the memset standard 'C' library where previously various options for different compiler/platforms are defined:


#include <string.h>

void sodium_memzero(void * const pnt, const size_t len) {
   memset(pnt,0,len);
} 
This approach however the function *memset* behavior might not be adequate. Relying on *memset* to zero memory, when invoked in this specific security context lead to problems as certain compilers take liberty of eliminating calls to *memset* under assumption its intent is to clear data that won't be subsequently needed. Therefore, the original code most likely was using these specific variants of memset to confirm compiler will not optimize out the memory zeroing calls.

A preservation of this concept is attainable. Below utilizes the standard *volatile* keyword C to guarantee the compiler will withstand from optimizing out the loop:


#include <stddef.h>

void sodium_memzero(void * const pnt, const size_t len) {
    volatile char * volatile pCharPnt = (volatile char * volatile)pnt;

    for(size_t i = 0; i < len; i++) {
        pCharPnt[i] = 0;
    }
}

Both provided solution defines function *sodium_zero* honoring its signature in original code also preserving the defined original logic. Although an understanding is necessary on the problem being attempted by the original solution to provide solution ensuring correct zeroing out takes place.