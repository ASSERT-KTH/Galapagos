static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    int m = n;
    OPEN_READER(re, s);
    av_assert2(m > 0 && m <= 25);
    UPDATE_CACHE(re, s);
    ++m;
    tmp = SHOW_UBITS(re, s, m - 1);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}