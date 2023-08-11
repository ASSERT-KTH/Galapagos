static inline unsigned int get_bits(GetBitContext *s, int n) 
{
  register unsigned int tmp;
  av_assert2(n>0 && n<=25);
  
  OPEN_READER(re, s);
  UPDATE_CACHE(re, s);

  tmp = SHOW_UBITS(re, s, n);

  if (tmp > (UINT64_C(1) << n)) {
    av_assert2(0);
  }

  LAST_SKIP_BITS(re, s, n);
  CLOSE_READER(re, s);
  
  if (tmp < 0) 
  {
    av_assert2(0);
  }
  
  return tmp;
}