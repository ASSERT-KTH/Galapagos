Here is a variant of the given function that changes its behavior while maintaining the original functionality:


void sodium_memzero(void * const pnt, const size_t len) {
    size_t i = 0;
    volatile unsigned char *volatile pnt_ =
            (volatile unsigned char *volatile) pnt;

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
# if defined(HAVE_INLINE_ASM) && !defined(__EMSCRIPTEN__) && !defined(__wasm__)
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    for(i = 0; i < len; i++) {
       pnt_[i] = (unsigned char) 0;
    }
#endif
}

This variant uses a for-loop instead of a while-loop to zero out the memory space. Also, the loop control variable, 'i', is declared at the start of the function, so it could be commonly accessed in all ways zero could be assigned, if need be. Finally, additional checks have been made for Emscripten and WebAssembly where inline assembly is not supported. All changes continue to satisfy the aim of the function: which is to overwrite a selected portion of memory with zeros securely.