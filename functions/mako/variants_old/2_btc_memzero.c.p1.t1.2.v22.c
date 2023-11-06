void btc_memzero(void *ptr, size_t len) {
  size_t i;

#if defined(BTC_HAVE_ASM) 
  if (len > 0) {

    for (i =0 ; i< len ; ++i){
        ((unsigned char*) ptr)[i] = 0;
    }
   
    __asm__ __volatile__ (
      :: "c" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    for (i = 0; i < len; ++i){
        ((unsigned char*) ptr)[i] = 0;
    }
  }
#else   
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
 
  if(len > 0){
     for (i = 0; i< len ; ++i){
        ((unsigned char*) ptr)[i] = 0;
     }
  }
#endif
}