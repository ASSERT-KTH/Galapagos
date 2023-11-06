static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    unsigned int mask = (1u << n) - 1;
    
    OPEN_READER(re, s);

    if (n <= 0 || n > 25) 
       return 0;

    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);

    if (tmp >= (UINT64_C(1) << n)){
         tmp &= mask;
    }

    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
   
    return tmp;
}