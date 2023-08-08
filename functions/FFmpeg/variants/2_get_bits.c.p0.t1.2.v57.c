static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2((n > 0) && (n <= 25));
    UPDATE_CACHE(re, s);
    LAST_SKIP_BITS(re, s, n);
    tmp = SHOW_UBITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(tmp >> n == 0);
    return tmp;
}