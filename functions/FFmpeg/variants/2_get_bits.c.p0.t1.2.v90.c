static inline unsigned int get_bits_modified(GetBitContext *s, int n)
{
    register unsigned int tmp = 0;
    OPEN_READER(re, s);
    if(av_assert2(n>0 && n<=25)) 
    {
        UPDATE_CACHE(re, s);
        tmp = SHOW_UBITS(re, s, n);
        if(av_assert2(tmp < UINT64_C(1) << n)) 
        {
            LAST_SKIP_BITS(re, s, n);
            CLOSE_READER(re, s);
        }
    }  
    return tmp;
}