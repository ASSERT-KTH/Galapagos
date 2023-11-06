static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    int valid_inputs = (n>0 && n<=25);
      
    if (!valid_inputs)
      n = 25;
      
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    
    if (tmp >= (unsigned int)(UINT64_C(1) << n))
        tmp = (unsigned int)(UINT64_C(1) << n) - 1;

    return tmp;
}