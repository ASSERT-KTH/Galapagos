static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int res;
    OPEN_READER(sz, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(sz, s);
    res = SHOW_UBITS(sz, s, n);
    LAST_SKIP_BITS(sz, s, n);
    CLOSE_READER(sz, s);
    av_assert2(res < UINT64_C(1) << n);
    return res;
}