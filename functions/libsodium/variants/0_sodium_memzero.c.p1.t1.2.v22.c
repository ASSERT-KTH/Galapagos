The following C++ re-implementation of the `sodium_memzero` still perserves its functionality (`set the memory to zero`), but slightly rearranges the controlled flow.

++
void sodium_memzero(void * const pnt, const size_t len) {
#ifdef HAVE_EXPLICIT_BZERO
    explicit_bzero(pnt, len);
#elif defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t)len, 0, (rsize_t)len) != 0) {
        sodium_misuse();
    }
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__  ("": :"r"(pnt): "memory");
# endif
#else 
    volatile unsigned char * pnt_ = (volatile unsigned char* ) pnt;
    size_t i = (size_t) 0U;

    for( ; i < len ; ++i)
    {
        pnt_[i] = 0U;
    }
#endif
}


Note that the logic and selection flow (`if-elif-else)` has changed somewhat, and a `for loop` has replaced the `while loop` for the final memory-zeroing operation, but the overall behavior of the function persists.

Please replace all specific modification, security or crypto functions, because they are dependent on the specific platform (or platforms) where a user or system does plan to deploy this `sodium_memzero` program variant.