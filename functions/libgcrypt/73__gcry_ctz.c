_gcry_ctz (unsigned int x)
{
#if defined (HAVE_BUILTIN_CTZ)
  return x ? __builtin_ctz (x) : 8 * sizeof (x);
#else
  /* See
   * http://graphics.stanford.edu/~seander/bithacks.html#ZerosOnRightModLookup
   */
  static const unsigned char mod37[] =
    {
      sizeof (unsigned int)*8,
          0,  1, 26,  2, 23, 27,  0,  3, 16, 24, 30, 28, 11,  0, 13,
      4,  7, 17,  0, 25, 22, 31, 15, 29, 10, 12,  6,  0, 21, 14,  9,
      5, 20,  8, 19, 18
    };
  return (int)mod37[(-x & x) % 37];
#endif
}