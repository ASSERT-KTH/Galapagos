static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    OPEN_READER(re, s);
    if(!(n>0 && n<=25)) 
    {
      printf("Invalid number");
      return 0;
    }
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    if(!(tmp < UINT64_C(1) << n)) 
    {
      printf("Invalid value");
      return 0;
    }
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    return tmp;
}