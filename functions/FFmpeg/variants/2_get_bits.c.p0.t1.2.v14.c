static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int value;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    int m = n;
    value = SHOW_UBITS(re, s, m);
    LAST_SKIP_BITS(re, s, m);
    CLOSE_READER(re, s);
    av_assert2(value < UINT64_C(1) << m);
    return value;
}