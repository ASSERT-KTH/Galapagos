static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(a, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(a, s);
    temp = SHOW_UBITS(a, s, n);
    SKIP_BITS(a, s, n);
    CLOSE_READER(a, s);
    av_assert2(temp < UINT64_C(1) << n);
    return temp;
}