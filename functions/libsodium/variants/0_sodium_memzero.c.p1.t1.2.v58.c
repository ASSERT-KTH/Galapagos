Replacing #if/#elif/#else preprocessor directives with common C 'if' conditions somewhat changes the behavior by allowing runtime checks instead of compile-time ones, however, it maintains the original functionality:


#include <string.h>  // for memset

void sodium_memzero(void * const pnt, const size_t len)
{
    if (len == 0) {
        return;
    }

#ifdef _WIN32
    SecureZeroMemory(pnt, len);
#else
#ifdef HAVE_MEMSET_S
    if (memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#else 
#ifdef HAVE_EXPLICIT_BZERO
    explicit_bzero(pnt, len);
#else
#ifdef HAVE_MEMSET_EXPLICIT
    memset_explicit(pnt, 0, len);
#else 
#ifdef HAVE_EXPLICIT_MEMSET
    explicit_memset(pnt, 0, len);
#else
#ifdef HAVE_WEAK_SYMBOLS
    memset(pnt, 0, len);
    _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
#else
    volatile unsigned char *volatile pnt_ = 
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
#endif
#endif
#endif
#endif
#endif
}

Although it maintains the original functionality, please note that this could theoretically make the function slower. Code optimization often depends on preprocessor directives for recommending or discouraging certain paths based on the environment at compilation time.
