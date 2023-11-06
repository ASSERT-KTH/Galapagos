Variant 1:

void btc_memzero(void *ptr, size_t len) {
  #if defined(BTC_HAVE_ASM)
    if (len) {
      memset(ptr, 0, len);
      asm volatile("" : : "r"(ptr) : "memory");
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);
  #else
    static void *(*volatile const_memset)(void *, int, size_t) = memset;
    if (len)
      const_memset(ptr, 0, len);
  #endif
}


Variant 2:

void btc_memzero(void* ptr, size_t size) {
  #if defined(BTC_HAVE_ASM)
    if(size != 0) {
      memset(ptr, 0x00, size);
      asm volatile ("" : : "r"(ptr) : "memory");
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, size);
  #else
    memset(ptr, 0X00, size);
  #endif
}

Note: Irrespective of definitions used for if/else conditions, array placing is 'ptr' and size is 'len' or 'size'.

Variant 3:

void btc_memzero(void *destruct, size_t len) {
  #if defined(BTC_HAVE_ASM)
    if (len != 0) {
      memset(destruct, 0, len);
      asm volatile ("" :: "r" (destruct) : "memory");
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(destruct, len);
  #else
    void *(*volatile memset_volatile)(void *, int, size_t) = memset;
    if (len)
      memset_volatile(destruct, 0, len);
  #endif
}

        
The contents within function matters rest of the code remains the same. Other than transformation such as converting {} to !!= removing non continuous spaces with continuous chars is possible.

Variant 4:


void btc_memzero(void *ptr, size_t len) {
  #if defined(BTC_HAVE_ASM)
    if (len > 0){
      memset(ptr, 0, len);
      __asm__ __volatile__ ("":: "r"(ptr): "memory");
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);
  #else
    static void *(*static_volatile_comb)(void *,int,size_t) = memset;
    if (len)
      static_volatile_comb(ptr, 0, len);
  #endif
}
