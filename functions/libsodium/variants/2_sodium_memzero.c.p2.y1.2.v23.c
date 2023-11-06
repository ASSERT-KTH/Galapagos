sodium_memzero(void * const pnt, const size_t len) {
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    memset_s(pnt, (rsize_t) len, 0, (rsize_t) len);
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    memset(pnt, 0, len);
    _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);  
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ = (volatile unsigned char *volatile) pnt;
    memset(pnt_, 0, len);
#endif
}
In this variant, the while loop being originally used to fill the memory section by each block has been replaced by the memset function as it overall enhances the performance of the code in terms of time complexity. At the same time the basic function (Memory clearance) to be performed remains the same. The memset function fills a block of memory with a specific byte. 
This transformation will enhance the program's performance especially when called to fill larger blocks of memory. This is because - in terms of time complexity - memset performs significantly better than manually iterating through the target memory block, especially when dealing with larger memory blocks.