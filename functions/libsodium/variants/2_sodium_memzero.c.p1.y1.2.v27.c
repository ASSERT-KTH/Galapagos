1.  Simple Conditional Statements Transformation:
 

sodium_memzero(void * const pnt, const size_t len)
{
    if (defined(_WIN32) && !defined(__CRT_INLINE)) {
        SecureZeroMemory(pnt, len);
    } else if (defined(HAVE_MEMSET_S)) {
        if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
            sodium_misuse(); /* LCOV_EXCL_LINE */
        } 
    } else if (defined(HAVE_EXPLICIT_BZERO)) {
        explicit_bzero(pnt, len);
    } else if (defined(HAVE_MEMSET_EXPLICIT)) {
        memset_explicit(pnt, 0, len);
    } else if (defined(HAVE_EXPLICIT_MEMSET)) {
        explicit_memset(pnt, 0, len);
    } else if (HAVE_WEAK_SYMBOLS) {
        if (len > 0U) {
            memset(pnt, 0, len);
            _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
        }
    # ifdef HAVE_INLINE_ASM
        __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
    # endif  
    } else {
        volatile unsigned char *volatile pnt_ =
            (volatile unsigned char *volatile) pnt;
        size_t i = (size_t) 0U;
        while (i < len) {
            pnt_[i++] = 0U;
        }
    }
}


2. Switch Case Transformation:
  
If the code consists of compiler specific defines which convert to either true or false, below code is a viable transformation.


sodium_memzero(void * const pnt, const size_t len)
{
    switch(true) {
    case (defined(_WIN32) && !defined(__CRT_INLINE)) :
        SecureZeroMemory(pnt, len);
        break;
    case defined(HAVE_MEMSET_S) :
        if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
            sodium_misuse();
        }
        break;
    case defined(HAVE_EXPLICIT_BZERO) :
        explicit_bzero(pnt, len);
        break;
    case defined(HAVE_MEMSET_EXPLICIT) :
        memset_explicit(pnt, 0, len);
        break;
    case defined(HAVE_EXPLICIT_MEMSET) :
        explicit_memset(pnt, 0, len);
        break;
    case HAVE_WEAK_SYMBOLS :
        if (len > 0U) {
            memset(pnt, 0, len);
            _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
        }
        break;
    default:
        volatile unsigned char *volatile pnt_ = (volatile unsigned char * volatile) pnt;
        size_t i = (size_t) 0U;
        while (i < len) {
            pnt_[i++] = 0U;   
        }
        break;
    }
}
