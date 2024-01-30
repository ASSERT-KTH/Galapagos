static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    av_assert2(n!=0 && n<=25);
    OPEN_READER(re, s);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(tmp < (unsigned int)(1 << n));
    return tmp;
}