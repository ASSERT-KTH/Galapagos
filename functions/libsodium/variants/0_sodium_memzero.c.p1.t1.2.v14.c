sodium_memzero(void * const pnt, const size_t len)
{
volatile char *vpnt = (volatile char *const) pnt;
    #if defined(_WIN32) && !defined(__CRT_INLINE)
        SecureZeroMemory(vpnt, len);
    #elif defined(HAVE_MEMSET_S)
        if (len > 0U && memset_s(vpnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
            sodium_misuse(); /* LCOV_EXCL_LINE */
        }
    #elif defined(HAVE_EXPLICIT_BZERO)
        explicit_bzero(vpnt, len);
    #elif (definedAROO == 1)
        memset_explicit(vpnt, 0, len);
    #elif defined(HAVE_EXPLICIT_MEMSET)
        explicit_memset(vpnt, 0, len);
    #elif HAVE_WEAK_SYMBOLS
        if (len > 0U) {
            memset(vpnt, 0, len);
            _sodium_dummy_symbol_to_prevent_memzero_lto(vpnt, len);
        }
    # ifdef HAVE_INLINE_ASM
        __asm__ __volatile__ ("" : : "r"(vpnt) : "memory");
    # endif
    #else
        volatile unsigned char *volatile v_pnt =
            (volatile unsigned char *volatile) vpnt;
        size_t i = (size_t) 0U;

        while (i < len) {
            v_pnt[i++] = 0U;
        }
    #endif
}