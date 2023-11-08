static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    unsigned int maxBitsVal = pow(2, n) - 1;
    
    OPEN_READER(re, s);
  
    av_assert2(n > 0 && n <= 25);
  
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
  
    if(tmp > maxBitsVal)
    {
        tmp %= (maxBitsVal + 1);
    }
  
    LAST_SKIP_BITS(re, s, n);
  
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << n);
  
    return tmp;
}