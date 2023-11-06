1.

void sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#else
    volatile unsigned char *vlc = (unsigned char*) pnt;

    for (size_t i = 0U; i < len; i++) {
        vlc[i] = 0;
    }
#endif
}

2.

void sodium_memzero(void * const pnt, const size_t len)
{
#if HAVE_WEAK_SYMBOLS && defined(HAVE_MEMSET)
    volatile char* pointer = (char*) pnt;

    if (len > 0U) {
        memset(pointer, 0, len);
    }
#ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pointer) : "memory");
#endif
#else
    volatile char * targetPointer = (char*) pnt;
    for(size_t j = 0U; j < len; j++){
        *targetPointer++ = 0;
    }
#endif
}

3.

void sodium_memzero(void * const pnt, const size_t len)
{
#if defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i;
    for (i = 0U; i < len; ++i) {
        pnt_[i] = 0U;
    }
#endif
}

4.

void sodium_memzero(void * const pnt, const size_t len)
{
#ifdef _WIN32
    SecureZeroMemory(pnt, len);
#else
    volatile unsigned char* pByte = (unsigned char*)pnt;
    size_t xPos;
    for (xPos = 0U; xPos < len; xPos++){
        pByte[xPos] = 0U;
    }
#endif
}