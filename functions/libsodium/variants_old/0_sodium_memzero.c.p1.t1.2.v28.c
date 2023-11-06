Sure, I'm basically keeping the original functionality intact which is to set a block of memory to zero while exploiting different standard and compiler-specific functions depending on the capabilities of the system it's compiled on. But I'll just rearrange those conditions to other similar ones:


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
#endif
#ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif

#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#endif
}

Here, the checks have been shifted so that both memory protection (#define/_WIN32 and !define/__CRT_INLINE) and explicit memory sets are done after all other zeroing methods. Depending on the concentration, this still accomplishes the same as before, zeroing out memory, but in a slightly different way.