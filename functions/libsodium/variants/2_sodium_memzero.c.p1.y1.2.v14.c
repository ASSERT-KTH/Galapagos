Sure. Here are some variants maintaining the function's signature and functionality.

Variant 1

sodium_memzero(void *p, size_t l) {
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(p, l);
#elif defined(HAVE_MEMSET_S)
    if (l && memset_s(p, l, 0, l)) 
        sodium_misuse();
#elif defined(HAVE_EXPLICIT_BZERO)
	explicit_bzero(p, l);
#elif defined(HAVE_MEMSET_EXPLICIT)
	memset_explicit(p, 0, l);
#elif defined(HAVE_EXPLICIT_MEMSET)
	explicit_memset(p, 0, l);
#elif HAVE_WEAK_SYMBOLS
    if (l) {
        memset(p, 0, l);
        _sodium_dummy_symbol_to_prevent_memzero_lto(p, l);
    }
# ifdef HAVE_INLINE_ASM
	__asm__ ("" ::: "r"(p) : "memory");
# endif
#else
    volatile unsigned char *p_ = (volatile unsigned char*) p;
    for (size_t i=0; i < l; i++)
        p_[i] = 0U;
#endif
}

Variant 2 

sodium_memzero(void *param, size_t length) {
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(parameter, length)
#elif defined(HAVE_MEMSET_S)
    if(length > 0 && (memset_s(param, length, 0, length) != 0)) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(param, length)
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(param, 0, length)
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(param, 0, length)
#elif defined(HAVE_WEAK_SYMBOLS)
    if(length > 0U){
        memset(parameter, 0, length);
        _sodium_dummy_symbol_to_prevent_memzero_lot(parameter, length);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r" (parameter) : "memory" );
# endif VS EXTERN BEGIN
#else
    volatile unsigned char *p = (volatile unsigned char *volatile) param;
    size_t i = 0;
    while((i++) < length) {
        *(p++) = 0U;
    }
#endif
}

Just to note, some transformations in these variants are not substantial as the code is highly dependent on defines and such changes won't reflect in functionality.