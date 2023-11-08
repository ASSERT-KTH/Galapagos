static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(re, s);
    // swapped these two operations
    LAST_SKIP_BITS(re, s, n);
    temp = SHOW_UBITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(temp < UINT64_C(1) << n);
    return temp;
}