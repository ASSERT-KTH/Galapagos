Below is a slight tweak on the original function sodium_memzero(void * const pnt, const size_t len). The change implemented more written out operation of char resetting inside the while loop. 


sodium_memzero(void * const pnt, const size_t len) {
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
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
    #ifdef HAVE_INLINE_ASM
        __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
    #endif
#else 
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while(i < len) {
        *(pnt_ + i) = (unsigned char) 0; 
        i++;
    }
#endif    
}
 

The while loop gets changed to:

while(i < len) {
    *(pnt_ + i) = (unsigned char) 0; 
    i++;
}
 

Here, instead using array reference to each offset byte in the memory, pointer arithmetic is used and indirection operator (*) is being used to specify that we are writing zero to each byte of the memory.