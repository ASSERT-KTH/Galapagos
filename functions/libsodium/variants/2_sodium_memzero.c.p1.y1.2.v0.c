Variant 1:C implementation using While loop

void sodium_memzero(void *pnt, const size_t len)
{
    volatile unsigned char *p = (volatile unsigned char *) pnt;
    size_t i = 0;
    while (i < len) {
        p[i] = 0;
        i++;
    }
}


Variant 2: Implementation with memcpy_s (MSVC) and memcpy function
 
#include <string.h>
void sodium_memzero(void *pnt, const size_t len)
{
#ifdef _MSC_VER
    memset_s(pnt, len, 0, len);
#else
    volatile unsigned char *px = (volatile unsigned char*)pnt;
    while (len--) *px++ = 0;
#endif
}


Variant 3: C implementation using ARM extensions
 
void sodium_memzero(void *pnt, const size_t len) 
{
#if __ARM_FEATURE_CRYPTO && !defined(__APPLE__)
    asm(
        "mov     x6, %2\n"  // cnt
        "mov     x5, %0\n"  // src
        "mov     w4, #0\n"  // val
        "1:\n"
        "subs    x6, x6, #1\n"
        "sturh   w4, [x5], #2\n"
        "b.gt    1b\n" buffer : : r"0, 2");
#else
    volatile unsigned char *p = (unsigned char *)pnt;
    size_t i = len;
    while (i != 0) {
        *p = 0;
        p++;
        i--;
    }
#endif
}
 

Variant 4: Implementation memsetting specific offset for multiple objects
  
void sodium_memzero(void * const pnt, const size_t len){
    char mode = '0';
    ValueType value = mode - '0';

    for (size_t index = 0; index < len; index += sizeof(value))
    {
        size_t numBytes = len - index;
        if (numBytes > sizeof(value))
            numBytes = sizeof(value);

        memcpy((BYTE*)pnt + index, &value, numBytes);
    }
}
