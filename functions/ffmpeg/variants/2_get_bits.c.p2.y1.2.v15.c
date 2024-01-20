static inline unsigned int get_bits(GetBitContext *s, int n)
{
    OPEN_READER(re, s);

    if(n>0 && n<=25){
        register unsigned int tmp;    
        UPDATE_CACHE(re, s);
        tmp = SHOW_UBITS(re, s, n);
        LAST_SKIP_BITS(re, s, n);
        CLOSE_READER(re, s);

        if(tmp < UINT64_C(1) << n)
            return tmp;
    }
  
    return -1;
}