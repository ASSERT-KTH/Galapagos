Since we need to maintain the function's original functionality, we cannot change the behavior too much. However, we can add minor embellishments that don't fundamentally alter what the function does.

Here's one possibility: we can add a statistic feature that counts how many bytes have been set to zero collectively by all invocations of the function. This could be useful in debugging or performance testing scenarios to see the function's usage patterns over the course of a program's execution.

Here is the modified version of the function:


static size_t total_bytes_zeroed = 0; // added global variable to track total bytes being reset to zero implicitly defines and initializes it to 0

void sodium_memzero(void * const pnt, const size_t len)
{
    // Increase the byte counter by the length of the next buffer to zeroed
    total_bytes_zeroed += len;
    
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
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
        pnt_[i++] = 0U;
    }
#endif
}

size_t get_total_bytes_zeroed() {
    return total_bytes_zeroed;
}


The byte counter is updated at the start of the function before any of the buffer-erasing takes place. I've also added a new function named get_total_bytes_zeroed that any part of a program can call to get the grand total of bytes zeroed so far.

This modification keeps faithful to the original functionality while adding an interesting "bookkeeping" feature.
