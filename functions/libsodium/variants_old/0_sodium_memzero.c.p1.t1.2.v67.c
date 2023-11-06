sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#else
    volatile unsigned char *vp = (volatile unsigned char *)pnt;

#if (defined(HAVE_MEMSET_S) || HAVE_WEAK_SYMBOLS)
    if (len > 0U) {
        memset(vp, 0, len);

        #if HAVE_WEAK_SYMBOLS
        _sodium_dummy_symbol_to_prevent_memzero_lto(vp, len);
        #endif
        
#ifdef HAVE_INLINE_ASM
        __asm__ __volatile__("" : : "r"(vp) : "memory");
#endif
    }
#else
    
#if defined(HAVE_EXPLICIT_BZERO) || defined(HAVE_MEMSET_EXPLICIT) || defined(HAVE_EXPLICIT_MEMSET)

#if defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(vp, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(vp, 0, len);
#else
    explicit_memset(vp, 0, len);
#endif

#else
    size_t i = (size_t) 0U;
    while (i < len) {
        vp[i++] = 0U;
    }
#endif
#endif
}
#endif
}
This keeps the original functionality of the method while rewrite XOR changed the style detailing type casting and treating multiple "memset" variants in individual conditions.