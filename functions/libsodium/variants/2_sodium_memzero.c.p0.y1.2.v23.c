void sodium_memzero(void * const pnt, const size_t len)
{
unsigned char *memory = (unsigned char*) pnt;
#if defined(_WIN32)
    SecureZeroMemory(memory, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(memory, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(memory, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(memory, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(memory, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(memory, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(memory, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(memory) : "memory");
# endif
#else
    volatile size_t iterator = 0U;
    while (iterator < len) {
        memory[iterator++] = 0U;
    }
#endif
}