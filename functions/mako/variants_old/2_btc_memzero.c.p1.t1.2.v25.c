Here's an alternative C code equivalent to the given function simplified and without compiler and platform-specific optimizations. Though optimized built-in variants exist for specific platforms, this variant presents a universal approach for all.


#include <stddef.h>

void btc_memzero(void *ptr, size_t len) {
    char *bytePtr = ptr;
    size_t i;

    for (i = 0; i < len; i++) {
        bytePtr[i] = 0;
    }
}

This function operates by casting the void pointer `ptr` to a `char` pointer (`bytePtr`). Since `char` is one byte in size, it then references over the buffer with `bytePtr[i]` one byte at a time from your passed pointer and initializes it to zero repeatedly for `len` times.

Remember, using special pragma calls or intrinsic functions, just like `memset` or `SecureZeroMemory`, may optimize it more suitably for specific compiler or system-based extensions. The change proposed would still achieve the same result. However, simd-style erasure given larger sizes could have significant performance implications. 

Also, notice that modern optimization in compilers can still lead your memory erasure to be elided, presenting the utilization in security-sensitive code a separate conversation due to the aspect of secure memory wiping.

Note that the general style, without optimizations, suits the 'simple function implementation' requirement and should function properly receiving appropriate pointer and size as argument.