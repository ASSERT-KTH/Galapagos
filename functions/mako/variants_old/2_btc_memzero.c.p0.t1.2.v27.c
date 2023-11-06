btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  /* Clearing memory in terms of block of sizeof(long)*/
  size_t lSize = sizeof(long);
  size_t i;
  for(i=0; i<len; i+=lSize)
     memset((char*)ptr+i, 0, (len-i)<lSize?(len-i):lSize);

  __asm__ __volatile__ (
    ""
    :: "r" (ptr)
    : "memory"
  ); 
#elif defined(_WIN32) && defined(SecureZeroMemory)
   DWORD blockSize = 4096; //Setting a block size
   char* p = (char*) ptr;
   while (len > blockSize) {
      SecureZeroMemory(p, blockSize);
      p += blockSize;
      len -= blockSize;
   }
   SecureZeroMemory(p, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  size_t off;
  /* Clearing memory block by block */
  for(off=0; off<len; off+=4096)
     memset_ptr((char*)ptr+off, 0, len-off<4096?len-off:4096);
#endif
}