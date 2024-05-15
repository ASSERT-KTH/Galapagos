vec_be_swap(block vec, vector16x_u8 be_bswap_const)
{
#ifndef WORDS_BIGENDIAN
  __asm__ volatile ("vperm %0, %1, %1, %2\n\t"
		    : "=v" (vec)
		    : "v" (vec), "v" (be_bswap_const));
#else
  (void)be_bswap_const;
#endif
  return vec;
}