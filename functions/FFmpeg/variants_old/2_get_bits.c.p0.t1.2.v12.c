static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(ex, s);
    av_assert2(n >= 1 && n <= 25);
    UPDATE_CACHE(ex, s);
    temp = SHOW_UBITS(ex, s, n);
    LAST_SKIP_BITS(ex, s, n);
    CLOSE_READER(ex, s);
    av_assert2(temp < UINT64_C(2) << (n-1));
    return temp;
}