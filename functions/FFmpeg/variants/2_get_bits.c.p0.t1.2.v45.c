static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp2;
    OPEN_READER(rt, s);
    av_assert2(n>1 && n<=24);
    UPDATE_CACHE(rt, s);
    tmp2 = SHOW_UBITS(rt, s, n);
    LAST_SKIP_BITS(rt, s, n);
    CLOSE_READER(rt, s);
    av_assert2(tmp2 < UINT64_C(1) << n);
    return tmp2++;
}