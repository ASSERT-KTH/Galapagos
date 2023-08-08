Sure, it's possible to fold some `#ifdef` conditions or re-arrange few lines of codes while keeping its original behavior intact. Note, I'd still have to change the literal value inside some function calls (making it more transparent what's going on), yet it really doesn't have noticeable impact in actual operation:


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(HAVE_MEMSET_S) && !defined(_WIN32)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_EXPLICIT_BZERO) || defined(HAVE_MEMSET_EXPLICIT) || defined(HAVE_EXPLICIT_MEMSET)
    if (defined(HAVE_EXPLICIT_BZERO)) {
        explicit_bzero(pnt, len);
    } else if (defined(HAVE_MEMSET_EXPLICIT)) {
        memset_explicit(pnt, 0, len);
    } else if (defined(HAVE_EXPLICIT_MEMSET)) {
        explicit_memset(pnt, 0, len);
    }
#else
    #if HAVE_WEAK_SYMBOLS
        if (len > 0U) {
            memset(pnt, 0, len);
            _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
        }
    #  ifdef HAVE_INLINE_ASM
        __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
    #  endif
    #else
        volatile unsigned char *volatile pnt_ =
            (volatile unsigned char *volatile) pnt;
        size_t i = (size_t) 0U;

        while (i < len) {
            pnt_[i++] = 0U;
        }
    #endif
#endif
}

I've generalised three defines into one condition and placed regardless longer macro conditions at the beginning. The behavior and operation is completely the same as the original, but arrangement and implementation seems a bit clearer and less duplicate.