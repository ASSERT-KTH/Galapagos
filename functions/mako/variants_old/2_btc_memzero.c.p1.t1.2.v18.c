Following is a code snippet for your requirement but this procedure might use more stack space because recursion needs to maintain multiple function call records instead of a simple one-time loop-based memset operation:


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
 if (len > 0) {
   if(len==1){
       memset(ptr, 0, len);
   }
   else {
       btc_memzero(ptr, len/2);
       btc_memzero(ptr+len/2, len - len/2);
   }

   __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
}
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0){
    if(len==1){
     SecureZeroMemory(ptr, len);
    }
    else{
     btc_memzero(ptr, len/2);
     btc_memzero(ptr+len/2, len - len/2);
    }
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  
  if (len > 0){
    if(len==1){
     memset_ptr(ptr, 0, len);
    }
    else {
     btc_memzero(ptr, len/2);
     btc_memzero(ptr+len/2, len - len/2);
    }
  }
#endif
}

This sample code is showing how you can call the same function with shorter memory size by using recursion, effectively masking the original internal operation with a recursive one while maintaining its original function to fill a memory block with zeros. The critical aspect to pay attention is that, for large values of len, this might overflow the program stack since now we are maintaining two stack-frames during the recursion calls to divide the memory area into halves until the base-case of size 1. Afterward, they start filling with zeros backtracking up the recursive calls chain. This inherently preserves the functionality yet garnishing the procedure (behavior) of achieving it.