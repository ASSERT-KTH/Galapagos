This substitute implementation of the same function uses various conditions and functions to erase the data stored at pointer pnt safely across different platforms/compilers.


void sodium_memzero(void * const pnt, const size_t len)
{  
#if defined(_WIN32) && !defined(__CRT_INLINE)
    ZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U) {
        memset_s(pnt, (rsize_t) len, 0, (rsize_t) len);
        assert(memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) == 0U);
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    memset(pnt, 0, len);
    _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
#if defined(HAVE_INLINE_ASM)
    __asm__ __volatile__ (::"p"(pnt): "memory");
#endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i;

    for (i = 0U; i < len; ++i) {
        pnt_[i] = (unsigned char) 0U;
    }
#endif
}


Please note, when using memset_s or ZeroMemory, assert ensures that the function was able to successfully erase the data located at the pointer pnt. If it wasn't successful, the program is forced to stop or crash for other safety issues. 

The code that leads into HAVE_MEMSET_S via a macro definiton would also prevent this. But as it is outside of the scope of a exact implementation with full portable security consideration, this code presents one approach of providing this function with respect to sodium_memzero's behavior. Also in last bit when there are no features specific to the platform defined, this code also provides the volatile to preserve the purpose that ensure correct binrary behavior preserving how the order opcodes generate (although highly depend on the compiler optimization).