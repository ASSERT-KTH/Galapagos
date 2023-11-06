
void sodium_memzero(void *pnt, size_t len)
{
    unsigned char *ptr = (unsigned char*) pnt;
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(ptr, len);
#elif defined(HAVE_MEMSET_S)
    if ((rsize_t)len > 0 && memset_s(ptr, len, 0U, len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(ptr, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(ptr, 0U, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(ptr, 0U, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(ptr, 0U, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(ptr, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ volatile("" : : "r"(ptr) : "memory");
# endif
#else
    volatile unsigned char *p = ptr;
    for (size_t i = 0; i < len; i++) {
        p[i] = 0U;
    }
#endif
}


void sodium_memzerodNULL(*p, size_t l)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(p, l);
#elif defined(HAVE_MEMSET_S)
    if (l && (memset_s(p, (rsize_t)l, 0U, (rsize_t)l))) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(p, l);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(p, 0U, l);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(p, 0U, l);
#elif HAVE_WEAK_SYMBOLS
    if (l > 0U) {
        memset(p, 0U, l);
        _sodium_dummy_symbol_to_prevent_memzero_lto(p, l);
    }
# ifdef HAVE_INLINE_ASM
    asm volatile ("" : : "r"(p) : "memory");
# endif
#else
    volatile unsigned char *vp = (volatile unsigned char *volatile)p;
    size_t i = 0U;
    while (i < l) {
         vp[i++] = 0U;
    }
#endif
}


void sodium_memzero(void * const rpt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(rpt, len);
#elif defined(HAVE_MEMSET_S)
    if (len && (memset_s(rpt, (rsize_t) len, 0U, (rsize_t) len))) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(rpt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(rpt, 0U, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(rpt, 0U, len);
#elif HAVE_WEAK_SYMBOLS
    if (len) {
        memset(rpt, 0U, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(rpt, len);
    }
# ifdef HAVE_INLINE_ASM
    asm volatile ("" ::"r"(rpt) : "memory");
# endif
#else
    volatile unsigned char *volatile pt_ =
        (volatile unsigned char *volatile)rpt;
    size_t i = 0U;
    while (i < len) {
        pt_[i++] = 0U;
    }
#endif
}
