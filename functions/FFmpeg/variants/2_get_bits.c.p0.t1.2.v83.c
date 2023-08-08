static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n >= 1 && n <= 25);

    if ( n >= 1 && n <= 25 ){

      UPDATE_CACHE(re, s);
      tmp = SHOW_UBITS(re, s, n);
      LAST_SKIP_BITS(re, s, n);
      CLOSE_READER(re, s);

      if (!(tmp < UINT64_C(1) << n)){
        tmp = UINT64_C(1) << n;
      }

    }else{
      return 0;
    }
   
    return tmp;
}