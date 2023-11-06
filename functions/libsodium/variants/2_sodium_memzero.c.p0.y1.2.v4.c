void sodium_memzero(void * const pnt, const size_t len) 
{
    #if defined(_WIN32) && !defined(__CRT_INLINE)
        memset(pnt, 0, len);
    #elif defined(HAVE_MEMSET_S)
        if (len > 0U) {
            memset_s(pnt, (rsize_t) len, 0U, (rsize_t) len);
            if (errno != 0) { /* if there is an error */
                sodium_misuse();
            }
        }
    #elif defined(HAVE_EXPLICIT_BZERO)
        bzero(pnt, len);
    #elif defined(HAVE_MEMSET_EXPLICIT) || defined(HAVE_EXPLICIT_MEMSET)
        memset(pnt, 0, len);
    #elif HAVE_WEAK_SYMBOLS
        if(len > 0U) {
            memset(pnt, 0, len);
            _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
        }
        # ifdef HAVE_INLINE_ASM
            __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
        # endif
    #else
        volatile unsigned char *new_pnt = (volatile unsigned char*)pnt;
        for(size_t i = 0; i < len; i++){
            new_pnt[i] = 0;
        }
    #endif
}