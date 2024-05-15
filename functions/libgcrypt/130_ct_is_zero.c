ct_is_zero (unsigned int a)
{
  /* Sign bit set if A == 0. */
  a = ~a & ~(-a);

  return a >> (sizeof(unsigned int) * 8 - 1);
}