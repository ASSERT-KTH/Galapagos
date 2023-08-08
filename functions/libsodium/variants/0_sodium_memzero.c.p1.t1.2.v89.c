Here is a variant of the sodium_memzero() function that should retain the same behavior. We have merely rearranged the order and structure a bit, but ensured all of the conditional directives and associated clean up techniques are still being called.

The main difference here is an increase in ease of understanding by implementing, e.g., different conditions on separate lines, adding descriptive comments, etc.

Note that changing the internal order might affect performance, but in typical usage scenarios the function above is often called only a small number of times, where any such effect would be negligible..


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    // use of a secure memory clean up for WIN32 defined 
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    // A non-null input is handled and misuse is hindered via sodium_misuse   
    if (len > 0U)
        if (memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0)
            sodium_misuse();
#elif defined(HAVE_EXPLICIT_BZERO)
    // provable zeroing of memory for BSD systems
    explicit_bzero(pnt, len); 
#elif defined(HAVE_MEMSET_EXPLICIT)
    // use of memset__explicit
    memset_explicit(pnt, 0, len); 
#elif defined(HAVE_EXPLICIT_MEMSET)
    // use of explicit setting of memory
    explicit_memset(pnt, 0, len); 
#elif HAVE_WEAK_SYMBOLS
    // traditional memset with other measures corrosponding to weak links
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
#ifdef HAVE_INLINE_ASM
    // specific standup gor parity register and making sure _sodium_dummy is not optimized away
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
#endif
} else { 
    size_t i = 0U;
    volatile unsigned char *volatile pnt_ = (volatile unsigned char *volatile) pnt;
    // General fallback
    while (i < len)
        pnt_[i++] = 0U;
    }
#endif
}
