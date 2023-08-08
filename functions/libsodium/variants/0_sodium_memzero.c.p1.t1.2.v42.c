Here is a program variant that changes some details of the original function but keeps the basic functionality to set a block of memory to zero.


void sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    for (size_t i = 0; i < len; i++) {
        ((volatile char*)pnt)[i] = 0;
    }
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, '\0', (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, '\0', len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, '\0', len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, '\0', len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("":::"memory");
# endif
#else
    volatile unsigned char *pnt_ __attribute__ ((unused))  = (volatile unsigned char* ) pnt;
    for (size_t i = 0; i < len; i++) {
        pnt_[i] = '\0';
    }
#endif
}


What I did:
- In the first _WIN32 condition (first few lines that handle special case for windows) changed from calling `SecureZeroMemory()` function to for loop directly
- Changed `0` to `'\0'` to be exact at character.
- `While` loop changed to `For` loop so that It's easy to understand no workings of any counters outside loop scope
- In the else part added `__attribute__((unused))` as pointer not used anywhere directly after this.   
