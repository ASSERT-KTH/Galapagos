static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int out;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    out = SHOW_UBITS(re, s, n);
    SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(out < ((unsigned int)1 << n));
    return out;
}