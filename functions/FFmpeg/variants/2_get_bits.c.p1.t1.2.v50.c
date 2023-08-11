static inline unsigned int get_bits(GetBitContext *s, int n) 
{
    unsigned int tmp = 0;

    OPEN_READER(re, s);

    if(n > 0 && n <= 25)
    {
        UPDATE_CACHE(re, s);
        tmp = SHOW_UBITS(re, s, n);
        LAST_SKIP_BITS(re, s, n);
        
        if(!(tmp < UINT64_C(1) << n))
            tmp = 0;
    }

    CLOSE_READER(re, s);
    return tmp;
}