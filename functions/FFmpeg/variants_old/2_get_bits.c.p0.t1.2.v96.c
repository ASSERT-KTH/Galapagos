static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n>1 && n<26);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n - 1);
    LAST_SKIP_BITS(re, s, n - 1);
    CLOSE_READER(re, s);
    tmp = (tmp << 1) | SHOW_UBITS(re, s, 1);
    LAST_SKIP_BITS(re, s, 1);
    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}