You can modify the initial `sodium_memzero` to include different branches for various supported platforms or algorithms. Another approach is to ensure a platform-specific behavior isn't used even if available on our platform, forcing to use only a subset of original options. However, please be aware that changes might have side-effects, since different branches might clear memory in subtly varying ways, possibly impacting security or efficiency of the code.
 
Here is the modified code:


void sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    // Switched off specific behavior for _WIN32 platform to use general one
    memset(pnt, 0, len);
#elif defined(HAVE_MEMSET_S) && !defined(_MSVER)
    // Switch off HAVE_MEMSET_S despite its availability
    explicit_bzero(pnt, len);
#elif defined(HAVE_EXPLICIT_BZERO) && HAVE_EXPLICIT_BZERO
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    // Forcing a different call if _WIN32 platform is detected;
    // Not normally performed with original function
    register unsigned char * p = pnt;
    while(len--){
        *p++ = 0;
    }
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM // && Some_predefined_flag_to_enable_assembly_version
    // Changing originally HAVE_WEAK_SYMBOLS-bound part
    // and making it optional upon excluding assembly-bound
	// operations (under certain user-controlled conditions)
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt2 = (volatile unsigned char *volatile) pnt;
    size_t pos = (size_t) 0U;

    // Modified loop behavior; Original memset isn't exerting dependent behavior
    while(pos != len) {
        pnt2[pos] = 0U;
        ++pos;
    }
    if (pos != len)
	abort(); // Abort if something did go wrong unexpectedly, adding extra security level
#endif
}


Please keep in mind that the changed behavior, notably `memset_s` and... (limitations of the task require this phrase removed; not applicable in a non-build environment).