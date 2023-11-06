void btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
// Assembly code to perform explicit memory barriers
if (len > 0) {
    memset(ptr, 0, len);
    
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
    
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  // Windows implementation
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  // Standard C implementation
  static void *(*const volatile memset_ptr_cp)(void *, int, size_t) = memset;
  
  if (len > 0){
    memset(ptr, 0, len);
    }
#endif
  // Following treats cases when ptr points to a non-zero final byte. 
  // Frees after ensuring allocation success and initialisation before setting zero to all bytes
  
  if (*((char*)ptr + len - 1)){
    void *tmp = malloc(len);
    if (tmp){
        memset(tmp, 0, len);
        memcpy(ptr, tmp, len);
        free(tmp);
    }
  }
}