Variant 1:

void sodium_memzero(void *const ptr, const size_t len){
#if defined(_WIN32) && !defined(__CRT_INLINE)
   SecureZeroMemory(ptr, len);
#elif defined(HAVE_MEMSET_S)
   if(len > 0U && (memset_s(ptr, (rsize_t)len, 0, (rsize_t)len) != 0)){
       sodium_misuse();
   }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(ptr, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(ptr, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(ptr, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U){
        memset(ptr, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(ptr, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(ptr): "memory");
#endif
#else
    volatile unsigned char * volatile p = (volatile unsigned char * volatile) ptr;
    size_t j = (size_t) 0U;

    while(j < len){
        p[j++] = 0U;
    }
#endif
}

Variant 2:
 
void sodium_memzero(void * const ptr_v, const size_t size){
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(ptr_v, len);
#elif defined(HAVE_MEMSET_S)
    if (size > 0U && memset_s(ptr_v, (rsize_t) len, 0, (rsize_t) len) != 0){
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(ptr_v, size);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(ptr_v, 0, size);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(ptr_v, 0, size);
#elif HAVE_WEAK_SYMBOLS
    if (size > 0U){
		memset(ptr_v, 0, size);
        _sodium_dummy_symbol_to_prevent_memzero_lto(ptr_v, size);
    }
#ifdef HAVE_INLINE_ASM
	__asm__ __volatile__ (" " ::: "memory");
#endif
#else
    volatile unsigned char * volatile t = (volatile unsigned char * volatile) ptr_v;
    size_t n = (size_t) 0U;
    while (n < size){
        t[n++] = 0U;
    }
#endif
}

