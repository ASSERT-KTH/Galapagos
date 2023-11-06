Here's a function variant which contains minor modifications but still preserving its original functionality. The basic idea remains the same across all block of code since it is meant to replace the data in memory with zeroes.  


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    ZeroMemory(pnt, len);  // zero the memory using ZeroMemory instead of SecureZeroMemory
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    bzero(pnt, len);  // bzero also works in same way as explicit_bzero on many systems
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset(pnt, 0, len);  // use standard memset over memset_explicit
#elif defined(HAVE_EXPLICIT_MEMSET)
    memset(pnt, 0, len);  // same here :-)
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    unsigned char * pnt_ = (unsigned char * ) pnt;
    for (size_t i = 0; i < len; i++) {   // Changings while loop with for loop.
        pnt_[i] = 0U;
    }
#endif
}


Note that I tried to preserve the functionality, but depending on the exact architecture/compiler/syscall specifications some parts might behave slightly differently. In a real value usage of low level details, be sure about the specifications and compatibility!