Here is the revised code.


sodium_memzero(void * const pnt, const size_t len) {

#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#else
    char *c_ptr = (char*)pnt;
    int cnt = 0;

    while (cnt < len){
     
    #if defined(HAVE_MEMSET_S)
         if (len > 0U && memset_s(&c_ptr[cnt], (rsize_t) 1, 0, (rsize_t) 1) != 0) {
             sodium_misuse(); 
         }
    #elif defined(HAVE_EXPLICIT_BZERO)
         explicit_bzero(&c_ptr[cnt], 1);
    #elif defined(HAVE_MEMSET_EXPLICIT)
         memset_explicit(&c_ptr[cnt], 0, 1);
    #elif defined(HAVE_EXPLICIT_MEMSET)
         explicit_memset(&c_ptr[cnt], 0, 1);
    #elif HAVE_WEAK_SYMBOLS
         memset(&c_ptr[cnt], 0, 1);
         _sodium_dummy_symbol_to_prevent_memzero_lto(&c_ptr[cnt], 1);
    # ifdef HAVE_INLINE_ASM
         __asm__ __volatile__ ("" : : "r"(&c_ptr[cnt]) : "memory");
    # endif
    #else
         volatile unsigned char *volatile pnt_ =
             (volatile unsigned char *volatile) &c_ptr[cnt];
         pnt_[0] =  0U;
    #endif

         cnt++;
    }
#endif
}


The difference from the original code: Instead of passing length as 'len' and address as 'pnt', I am breaking it down and calling memset one byte at a time. And the function is called for each byte. Also, counter 'i' has been replaced with counter 'cnt'. Code in all branches becomes almost the same. The function will slow down.