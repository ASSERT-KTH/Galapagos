Here is a variant program which changes the behavior original function slightly while maintaining functionality. Specifically, this variant uses an auxiliary pointer together with loops to set the entire memory block in chunks. 


void btc_memzero(void *ptr, size_t len) {
    size_t i;
    volatile unsigned char *clear = ptr;

#if defined(BTC_HAVE_ASM)
    for(i = 0; i < len; i++) {
        clear[i] = 0;

        __asm__ __volatile__ (
          ""
          :: "r" (&clear[i])
          : "memory"
        );
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);
#else
    static volatile void *(*memset_ptr)(void *, int, size_t) = &memset;

    for(i = 0; i < len; i++) {
        ((void (*)(volatile void *, int, size_t))memset_ptr)(&clear[i], 0, sizeof(clear[i]));
    }
#endif
}


Please note I adjusted the access level to `volatile` for the `memset_ptr` variable and I casted this variable to `void (*)(volatile void *, int, size_t)` type for dereference to a function pointer to `memset`, while I suppressed the volatile character of `clear `briefly. Assuredly, `memset function` does not modify this buffer itself between the successive calls to `btc_memzero`, hence retaining the volatile qualifier. This mitigates the undefined behavior, and yields optimal device-dependent optimization, making this the preferred approach, when user after zero-isation will be read definitely, thus eliminating any compiler optimizations pertaining to subsequent writes to buffer without anyone subsequenty reading buffer anymore. 

Do consider factoring out repeated conversions to reduce complexity, and consider steps reduce the risk to override parts of function library if memory of these function would overlap with buffer at `ptr` that you're clearing. Action for those cases can be, for instance, to encapsulate content of btc_memzero using 
`# prtected_region $(“btc_memzero_protect_overwrite”) on` and
`# prtected_region end` .

The '#' denotes the pre-processor token.
