static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    av_assert2(n>0 && n<=25);
    OPEN_READER(re, s);
    UPDATE_CACHE(re, s);
    if (n > 0)
    {
        tmp = SHOW_UBITS(re, s, n);
        if(tmp < UINT64_C(1) << n)
        {
            LAST_SKIP_BITS(re, s, n);
        }
    }
    CLOSE_READER(re, s);
    return tmp;
}