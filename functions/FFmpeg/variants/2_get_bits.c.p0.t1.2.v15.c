static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int maxValue;
    unsigned int tmp;
    OPEN_READER(re, s);
    maxValue = (UINT64_C(1) << n);
    av_assert2(n > 1 && n < 25);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n-1);
    if (tmp >= maxValue/2)
    {
        av_assert0(0);
    }
    LAST_SKIP_BITS(re, s, n-1);
    CLOSE_READER(re, s);
    return tmp;
}