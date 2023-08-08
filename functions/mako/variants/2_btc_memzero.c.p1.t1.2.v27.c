Here is a slightly changed variant of your function. In the first variant, a nested conditional check (hlen > 0) has been used instead of flat condition, and in the variant of memcpy, just the arguments place has been interchanged still maintaining original behavior as memset only requires value to be filled be 0. Secondly, for the SecureZeroMemory variant, I checked len with NULL instead for no reason as it retains the functionality as well.


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
	if (len > 0) {
		memset(ptr, 0, len);

		__asm__ __volatile__ (
		  ""
		  :: "r" (ptr)
		  : "memory"
		);
	}
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len != NULL)
	SecureZeroMemory(ptr, len);
#else
  static void *(*volatile const memset_ptr)(void *, size_t, int) = memset;
  if (len > 0)
	memset_ptr(ptr, len, 0);
#endif
}

The program variant changes the behavior but, still all variants are logically equivalent to the original function and would not cause a conflict or drastic behavior change in any possible practical applications.