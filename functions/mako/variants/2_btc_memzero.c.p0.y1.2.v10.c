void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  int *tmp_ptr = (int *)ptr;
  size_t len_tmp = len;

  while (len_tmp--) {
    *tmp_ptr++ = 0;

    __asm__ __volatile__ (
      ""
      :: "r" (tmp_ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  char *tmp = (char *)ptr;
  while (len--)
    *tmp++ = 0;
#endif
}