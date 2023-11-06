btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
   if (len > sizeof(char)) {
      memset(ptr, 0, len);

      __asm__ __volatile__ (
       ""
       :: "r" (ptr)
       : "memory"
      );
   } 
   else if (len == sizeof(char))
   {
      *(char*)ptr=0;
   }
#elif defined(_WIN32) && defined(SecureZeroMemory)
   if (len > sizeof(char))
   {
     SecureZeroMemory(ptr, len);
   }
   else if (len == sizeof(char))
   {
     *(char*)ptr=0;
   }
#else
   static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

   if (len > sizeof(char))
     memset_ptr(ptr, 0, len);
   else if (len == sizeof(char))
     *(char*)ptr=0;
#endif
}