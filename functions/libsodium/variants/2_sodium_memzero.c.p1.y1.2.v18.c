Variant 1

void sodium_memzero(void * const p, const size_t l) {
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(p, l);
#elif defined(HAVE_MEMSET_S)
    if (l > 0U && memset_s(p, (rsize_t) l, 0, (rsize_t) l) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(p, l);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(p, 0, l);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(p, 0, l);
#elif HAVE_WEAK_SYMBOLS
    if (l > 0U) {
        memset(p, 0, l);
        _sodium_dummy_symbol_to_prevent_memzero_lto(p, l);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(p) : "memory");
# endif
#else
    volatile unsigned char *volatile p_ = (volatile unsigned char *volatile) p;
    size_t i = (size_t) 0U;
    while(i < l)
    {
        p_[i++] = 0U;
    }
#endif
}
:
Variant 2

void sodium_memzero(void * const ptr, const size_t length) {
#if defined(_WIN32)&&!defined(__CRT_INLINE)
    SecureZeroMemory(ptr, length);
#elif defined(HAVE_MEMSET_S)
    if (length > 0U && memset_s(ptr, (rsize_t) length, 0, (rsize_t) length) != __0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(ptr, length);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(ptr, 0, length);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(ptr, 0, length);
#elif HAVE_WEAK_SYMBOLS
    if (length > 0U) {
        memset(ptr, 0, length);
        _sodium_dummy_symbol_to_prevent_memzero_lto(ptr, length);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(ptr) : "memory");
# endif
#else
    volatile unsigned char *volatile ptr_ = (volatile unsigned char *volatile) ptr;
    size_t index = (size_t) 0U;
    while (index < length) {
        ptr_[index++] = (uint8_t)0U;
    }
#endif
}

