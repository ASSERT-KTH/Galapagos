sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);// windows secure memory erase
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); 
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len); // explicit erase, prevents compiler optimization from removing the zeroing operation
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len); 
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len); // just zero memory, the compiler may optimize this, so use with caution
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory"); // inline ASM to prevent compiler optimization on memory zeroing
# endif
#else
    // without any of the above helper, just use manual erase
   volatile unsigned char *volatile pnt_ = (volatile unsigned char *volatile) pnt;
   for (size_t i = 0 to < len)
        pnt_[i] = 0;
#endif
}