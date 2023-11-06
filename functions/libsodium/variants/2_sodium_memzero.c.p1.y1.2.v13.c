
void sodium_memzero(void * const pnt_, const size_t type_len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt_, type_len);
#elif defined(HAVE_MEMSET_S)
    if (type_len > 0U && memset_s(pnt_, (rsize_t) type_len, 0, (rsize_t) type_len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt_, type_len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt_, 0, type_len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt_, 0, type_len);
#elif HAVE_WEAK_SYMBOLS
    if (type_len > 0U) {
        memset(pnt_, 0, type_len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt_, type_len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt_) : "memory");
# endif
#else
    volatile unsigned char *volatile a_pnt =
        (volatile unsigned char *volatile) pnt_;
    size_t a_i = (size_t) 0U;

    while (a_i < type_len) {
        a_pnt[a_i++] = 0U;
    }
#endif
}



void sodium_memzero(void* mem_pointer, const size_t byte_quantity)
{
#ifdef _WIN32
    SecureZeroMemory(mem_pointer, byte_quantity);
#elif defined(HAVE_MEMSET_S)
    if (byte_quantity > 0U) 
    {
        if (memset_s(mem_pointer, (rsize_t) byte_quantity, 0, (rsize_t) byte_quantity) != 0) 
            sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(mem_pointer, byte_quantity);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(mem_pointer, 0, byte_quantity);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(mem_pointer, 0, byte_quantity);
#elif HAVE_WEAK_SYMBOLS
    if (byte_quantity > 0U) 
    {
        memset(mem_pointer, 0, byte_quantity);
        _sodium_dummy_symbol_to_prevent_memzero_lto(mem_pointer, byte_quantity);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(mem_pointer) : "memory");
# endif
#else
    volatile unsigned char *volatile cur_pnt =
        (volatile unsigned char *volatile) mem_pointer;
    size_t index = (size_t) 0U;

    while (index < byte_quantity) {
        cur_pnt[index++] = 0U;
    }
#endif
}
