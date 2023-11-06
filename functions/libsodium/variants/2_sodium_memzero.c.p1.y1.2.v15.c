Variant 1:
 
sodium_memzero(void * const pnt, const size_t len) 
{ 
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len); 
#elif defined(HAVE_MEMSET_S) 
   if (len > (size_t) 0 && 
   memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) 
    { 
        sodium_misuse();
    } 
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len); 
#elif defined(HAVE_MEMSET_EXPLICIT) 
    memset_explicit(pnt, 0, len); 
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > (size_t) 0U) { memset(pnt, 0, len); _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);}
#ifdef HAVE_INLINE_ASM
    asm volatile ("" : : "r"(pnt) : "memory");
#endif
#else 
size_t i;
volatile unsigned char *pnt_;
pnt_ = (volatile unsigned char * volatile)pnt; 
for (i=0; i<len; i++) 
{ pnt_pic [i] = 0U;}
#endif
}


Variant 2:

sodium_memzero(void * const p, const size_t l)
{ 
#if defined(WIN32) && !defined(CRT_INL)
    SecureZeroMemory(p, l);
#elif defined(HAVE_SET_APPART_MEMORY)
   if (l > 0U && memset_s(p, l, 0, l) != 0) 
    {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_ZERO_MEMORY)
    explicit_bzero(p, l);
#elif defined(HAVE_CLEAR_MEMORY)
    clear_memory(p, 0, l);
#elif defined(HAVE_EXPLICIT_CLEAR)
    explicit_clear(p, 0, l);
#elif HAVE_SYMBOLS
    if (l > 0U) {
        clear_memory_var(p, 0, l);
        symbol_to_prevent_memzero_lto(p, l);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ (""::"r"(p):"memory");
# endif
#else
    volatile unsigned char *volatile p_v = (volatile unsigned char volatile*) p;
    size_t i = (size_t)0U;

    while (i < l) {
        p_v[i++] = 0U;
    }
#endif 
}
