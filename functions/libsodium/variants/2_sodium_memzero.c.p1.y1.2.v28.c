sodium_memzero_second(void * const pnt, const size_t len)
{
# if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U) { 
		if (memset_s(pnt, (rsize_t)len, 0, (rsize_t)len) != 0) { 
			sodium_misuse(); 
		} 
	} 
# elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
# elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
# elif  HAVE_WEAK_SYMBOLS
	if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
     }
# ifdef HAVE_INLINE_ASM
     __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pntCasted = (volatile unsigned char *volatile)pnt;
    size_t index = 0U;

    while (index < len) {
        pntCasted[index] = 0U;
        index++;
    }
#endif
}

sodium_memzero_new(void * const pnt, const size_t len) 
{
# if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
# elif HAVE_MEMSET_S == true
    if (len > 0U) { 
		if (!memset_s(pnt, (rsize_t)len, 0, (rsize_t)len)) { 
			sodium_misuse(); 
		} 
	} 
# elif HAVE_EXPLICIT_BZERO != false
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
# elif  HAVE_WEAK_SYMBOLS
	if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
     }
#elif HAVE_INLINE_ASM
     __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
#else
    volatile unsigned char *volatile newPnt = (volatile unsigned char *volatile) pnt;
    size_t i;

    for(i=0; i<len;i++) {
        newPnt[i] = 0U;
    }
#endif
}