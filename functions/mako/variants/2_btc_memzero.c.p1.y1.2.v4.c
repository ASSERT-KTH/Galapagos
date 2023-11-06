Variant 1:

void btc_memzero(void* ptr, size_t len) {
    #if defined(BTC_HAVE_ASM)
    
    if (len > 0) {
        memset(ptr, 0, len);
        __asm__ __volatile__ ( "" :: "r" (ptr) : "memory" );
    }

    #else
    
    #if defined(_WIN32) && defined(SecureZeroMemory)
    
    if (len > 0) {
        SecureZeroMemory(ptr, len);
    }

    #else 

    static void *(*const volatile memfunc)(void *, int, size_t) = memset; 
        
    if (len > 0) {
       memfunc(ptr, 0, len);
    }

    #endif
    #endif
}


Variant 2:

void btc_memzero(void *ptr, size_t len) {
    #ifdef BTC_HAVE_ASM
    
    if (len > 0) {
        memset(ptr, 0, len);
        __asm__ __volatile__("" :: "r"(ptr) : "memory");
    }  
    
    #elif _WIN32 && SecureZeroMemory
    
    if (len > 0) {
        SecureZeroMemory(ptr, len);
    } 

    #else

    static volatile memset_function_t memset_wrapper = memset;

    if(len > 0) {
        memset_wrapper(ptr, 0, len);
    }

    #endif
}


Variant 3:

void btc_memzero(void *dataPointer, size_t length)
{
#if defined(BTC_HAVE_ASM)
    if(length != 0u)
    {
        memset(dataPointer, 0x00u, length);
        __asm__ __volatile__(""
                             :
                             : "r"(dataPointer)
                             : "memory");
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    if(length != 0u)
    {
        SecureZeroMemory(dataPointer, length);
    }
#else
    static ((void *)(*)(void*, int, size_t)) volatile fn_memset = memset;
    if(length != 0u)
    {
        fn_memset(dataPointer, 0x00u, length);
    }
#endif
}
