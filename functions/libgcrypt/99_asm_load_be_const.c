asm_load_be_const(void)
{
#ifndef WORDS_BIGENDIAN
  return ALIGNED_LOAD (&vec_bswap32_const_neg, 0);
#else
  static const block vec_dummy = { 0 };
  return vec_dummy;
#endif
}