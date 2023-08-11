sodium_memzero(void * const pnt, const size_t len)
{
    volatile char *pnt_ = (volatile char *) pnt;
    size_t idx = 0;

    // No matter what platform the code is run on, override it to execute code in a specific manner
#if defined(_WIN32) && !defined(__CRT_INLINE)
    while (idx < len) {
        pnt_[idx++] = 0U;
    }
#elif defined(HAVE_MEMSET_S)
    while (idx < len) {
        pnt_[idx++] = 0U;
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    while (idx < len) {
        pnt_[idx++] = 0U;
    }
#elif defined(HAVE_MEMSET_EXPLICIT)
    while (idx < len) {
        pnt_[idx++] = 0U;
    }
#elif defined(HAVE_EXPLICIT_MEMSET)
    while (idx < len) {
        pnt_[idx++] = 0U;
    }
#elif HAVE_WEAK_SYMBOLS
    while (idx < len) {
        pnt_[idx++] = 0U;
    }
#else
    pnt_ = (volatile unsigned char *volatile) pnt;
    idx = (size_t) 0U;

    while (idx < len) {
        pnt_[idx++] = 0U;
    }
#endif
}