static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    int actual_bits = n > 25 ? 25 : n;
    av_assert2(actual_bits > 0);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, actual_bits);
    LAST_SKIP_BITS(re, s, actual_bits);
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << actual_bits);
    return tmp;
}