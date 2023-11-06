sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
  SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#else
    char * charPnt = (char*)pnt;
 
    for(unsigned long i = 0; i < len; i++) {
 
#if HAVE_WEAK_SYMBOLS 
        min_memset(&pnt[i], 0, 1); 
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, 1); 
        
#   ifdef HAVE_INLINE_ASM
        __asm__ __volatile__ ("" : : "r"(&pnt[i]) : "memory");
#   endif 
#else
        volatile unsigned char *volatile tempPnt = 
            (volatile unsigned char *volatile) &charPnt[i];
        *tempPnt = 0U;       
#endif
    }   
#endif            
} 

In this variation, multipurpose functions are replaced by a simple solution with equivalent functionality: you notice, when length is larger than zero: it overwrites every byte in this memory space starting from the initial pointer to maintain the original overhead functionality. Notably, architectural variability is preserved accurately. The if-else chain which sets the filling/erasing way according to present libraries, architecture, and flags still performs its original function but now on a smaller scale. However, these conditional compilation commands help to satisfy different system requirements. Their purpose is to minimize possible risks associated with possible issues or vulnerabilities within specific system libraries. 

This micro-operations somehow are more costly methodically (more cycles) rather than once by calling a function in advance, but it serves to individuate and atomize functionality traditionally connected to bulk operations on memory - and consequently it elaborates otherwise pointless processors (not working that means essentially extending their energy activity) interactions into memory. It does not, contribute to increasing security but offers rather peculiar coding style preserving requirements.