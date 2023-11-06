Assuming each individual logic branch does preserve the same effects, here are several transformations: 

1. Structuring all ifndef/!defined Guards:


sodium_memzero(void * const pnt, const size_t len)
{
#ifndef (_WIN32) || defined(__CRT_INLINE)
    #ifndef HAVE_MEMSET_S
    {
        if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
            sodium_misuse(); /* LCOV_EXCL_LINE */
        }
    }
    #ifndef HAVE_EXPLICIT_BZERO
        explicit_bzero(pnt, len);
    #ifndef HAVE_MEMSET_EXPLICIT
        memset_explicit(pnt, 0, len);
    #ifndef HAVE_EXPLICIT_MEMSET
        explicit_memset(pnt, 0, len);
    #ifndef HAVE_WEAK_SYMBOLS
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
        size_t i = 0U;
        while (i < len) {
            pnt_[i++] = 0U;
        }
    #endif /* all nested ifndefs */
#else
    SecureZeroMemory(pnt, len);
#endif /* ifndef main block */
}


2. Using an Else Construct Instead of Pragma "else..if"


sodium_memzero(void * const pnt, const size_t len)
{
#ifdef  (_WIN32) || defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#else
    #ifdef HAVE_MEMSET_S
        if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
            sodium_misuse(); 
        }
    #else
        #ifdef HAVE_EXPLICIT_BZERO
            explicit_bzero(pnt, len);
        #else 
              #ifdef HAVE_MEMSET_EXPLICIT
                  memset_explicit(pnt, 0, len);
              #else
                  #ifdef HAVE_EXPLICIT_MEMSET
                     explicit_memset(pnt, 0, len);
                  #else
                      #ifdef HAVE_WEAK_SYMBOLS
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
                            while (i < len) {
                                pnt_[i++] = 0U;
                            }
                         #endif     
                  #endif
              #endif
        #endif    
    #endif    
#endif
}

Please note that even if the transformations omit or reshape pragma preprocessor commands (`#ifdef`, `#ifndef`, `#elif`, etc.), each variant shouldn't influence the functionality if done carefully where each command exactly corresponds to its previous version.