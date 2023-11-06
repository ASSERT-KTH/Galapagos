I understand that by original functionality, you mean that the function should still clear a block of memory (set to zeros) securely. While making a change that affects the behavior and ideally is a potentially more secure way to clear the memory. An addition could be randomization before the memory clearing.


// The following program variant first sets the memory to a random value.
// Then, it clears deepens the secure deletion, as reversing the memory back to zero might be a slightly more difficult
// process if someone attempts to recover data.

#include <stdlib.h>

sodium_memzero(void * const pnt, const size_t len)
{
    void *temp = malloc(len);
    if (!temp) return;  // failed to allocate memory

#if defined(_WIN32) && !defined(__CRT_INLINE)
    rand_s(temp, len);
    memcpy(pnt, temp, len);
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    rand_s(temp, len);
    memcpy(pnt, temp, len);
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    rand_s(temp, len);
    memcpy(pnt, temp, len);
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    rand_s(temp, len);
    memcpy(pnt, temp, len);
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    rand_s(temp, len);
    memcpy(pnt, temp, len);
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        rand_s(temp, len);
        memcpy(pnt, temp, len);
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = rand() % 256;
    }

    i = 0U;
    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif

    free(temp);
}


Before setting each memory byte to zero, it sets it with a random value confirmed by the ram_s() or rand() function depending upon the existence of certain functions. Deallocation of the space taken by heap is also important after its utilization is over.