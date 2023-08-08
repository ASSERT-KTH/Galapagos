static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int c;
    OPEN_READER(bc, s);
    av_assert2(n>0 && n<=27);
    UPDATE_CACHE(bc, s);
    c = SHOW_UBITS(bc, s, n);
    LAST_SKIP_BITS(bc, s, n);
    CLOSE_READER(bc, s);
    av_assert2(c < UINT64_C(1) << n);
    return c;
}