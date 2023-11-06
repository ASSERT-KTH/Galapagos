static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int result;
    OPEN_READER(rc, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(rc, s);
    result = SHOW_UBITS(rc, s, n);
    LAST_SKIP_BITS(rc, s, n);
    CLOSE_READER(rc, s);
    av_assert2(result < UINT64_C(1) << n);
    return result;
}