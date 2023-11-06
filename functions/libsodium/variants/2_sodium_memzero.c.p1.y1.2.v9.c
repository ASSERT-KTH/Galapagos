#ifdef HAVE_TRY_CATCH
#include<exception>
void sodium_memzero(void * const pnt, const size_t len) {
    if(pnt == NULL) throw std::invalid_argument("Received null pointer");

    try {      
#if defined(_WIN32) && !defined(__CRT_INLINE)
        SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
        if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
            sodium_misuse();
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
        size_t i = 0U;

        while (i < len) {
            pnt_[i++] = 0U;
        }
#endif
       
    } catch(const std::exception & e) {
        // handle exception
    }
}
#endif

// Variant 2
void sodium_memzero(void * const pnt, const size_t len) {
    if(pnt == NULL) return;

#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
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
    if (len > 0U) {
        volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
        size_t i = 0U;

        while (i < len) {
           pnt_[i++] = 0U;
        }
    }
#endif
}