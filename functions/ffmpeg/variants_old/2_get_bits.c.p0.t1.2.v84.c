static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    bool validN = n > 0 && n <= 25;

    OPEN_READER(re, s);
    av_assert2(validN);
    
    if (validN)
    {   
        UPDATE_CACHE(re, s);
        tmp = SHOW_UBITS(re, s, n);
        LAST_SKIP_BITS(re, s, n);
    }
    else
    {
        tmp = 0;
    }

    CLOSE_READER(re, s);
    av_assert2(tmp <= UINT64_C(1) << n);

    return tmp;
}