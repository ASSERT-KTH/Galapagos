btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {

    __asm__ __volatile__ (
      "movq	%0, %%rax 	\n\t"
      "rep	stosb		"
      :
      :"r" ((unsigned char)0), "D"  ((unsigned char *)ptr), "c"  (len)
      :"rax"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#elif defined(_WIN32)
  for(size_t i = 0; i < len; ++i)
      ((unsigned char *)ptr)[i] = 0;
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    memset_ptr(ptr, 0, len);
#endif
}