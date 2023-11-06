Here's a variant that should accomplish the same thing overall, primarily using inline assembly. As a high level approach, for each 32-bit chunk of the array, it loads that chunk into a register clears it and then writes it back.


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0)
{
	volatile int *p = rbegin;
	while (p < rend) {
		*p = 0;
		p++;
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
#ifdef HAVE_INLINE_ASM
    for(size_t i = 0; i < len/4; ++i) {
    	unsigned reg = 0;
	__asm__ __volatile__ (
    		"mov %1, %0"
    		: "=r" ((unsigned) (__volatile__))
		: "m" (((unsigned*)pnt)[i])
		: "memory"
	);

  	__asm__ __volatile__ (
    		"mov %1, %0"
    		: "=m" (((unsigned*)pnt)[i])
    		: "r" (reg)
    		: "memory"
  	);
    }
#endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
     size_t i = (size_t) 0U;

    while (i < len) {
         pnt_[i++] = 0U;
    }
#endif
}


Please note that the added inline assembly here isn't ultra efficient or even particularly optimized, but it's there to demonstrate an alternative approach you could take for directly clearing memory. Also inline assembly is not portable between different compilers or different processor architectures, so it should be used sparingly and generally as a last resort. Always check your assembly output if you're red into performance concerns.