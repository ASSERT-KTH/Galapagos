static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int ss;  // don't use register keyword, it is deprecated in most moder CNC 
    OPEN_READER(rx, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(rx, s);
    ss = SHOW_UBITS(rx, s, n);
    LAST_SKIP_BITS(rx, s, n);
    CLOSE_READER(rx, s);
    av_assert2(ss < UINT64_C(1) << n);
    return ss;
}