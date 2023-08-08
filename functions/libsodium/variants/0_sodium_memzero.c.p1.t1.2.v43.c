Your question appears to ask for a different implementation of the `sodium_memzero(void * const pnt, const size_t len)` function. I've included a simpler version below which should preserve functionality. However, it is generally encouraged to use system-provided functionality to avoid bugs, security issues and compatibility issues as can be seen in the original function. Anyway, a simple standard function could be written as follows:


#include <string.h> // required for memset function

sodium_memzero(void * const pnt, const size_t len)
{
    memset(pnt, 0, len);
}

Similar to the previous function, this code sets every byte in a specific memory location block (the first `len` bytes of the memory area pointed to by `pnt`) to zero.
Any behavior change in the function could potentially result in altered functionality, potentially leading to security issues and other bugs due to lack of buffer-address overwriting measures in the original function. As such the function maintains its core functionality - setting a buffer's contents to zero - across a number of API and platform specifications for safety.