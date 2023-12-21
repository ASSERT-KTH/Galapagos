static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(b, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(b, s);
    temp = SHOW_UBITS(b, s, n);
    LAST_SKIP_BITS(b, s, n);
    CLOSE_READER(b, s);
    av_assert2(temp < UINT64_C(1) << n);
    return temp;
}