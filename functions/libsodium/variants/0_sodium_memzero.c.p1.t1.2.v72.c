void sodium_memzero(void * const pnt, const size_t len) 
{
    unsigned char* bytePointer = (unsigned char*)pnt;

#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#else
    for (size_t i = 0; i < len; i++)
    {
        bytePointer[i] = 0;
    }
    
#ifdef HAVE_WEAK_SYMBOLS
    _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#endif

#endif
}