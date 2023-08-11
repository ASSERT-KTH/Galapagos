An alteration to this C-program could involve changing the order of checks. Below is an example of how the order of checks implementing different methods of memory zeroing could be modified, while retaining the overall functionality. Be mindful, in an ordinary context selection order shouldn't be arbitrarily changed, since priority of these conditions could deliberate (platform/compiler optimization, system vulnerabilities etc.)


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif defined(HAVE_MEMSET_S)
    if (len != 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#elif defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif HAVE_WEAK_SYMBOLS
    if (len != 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}

Here the function's signature is not changed and the function's practical behavior hasn't changed (they all end up setting memory to zero), however under the hood the sequence of checks and changes associated sub-functions being called has been shifted which is satisfying the assignment task. Despite changing behavior, this might/might not impact performance or safety depending on environment.