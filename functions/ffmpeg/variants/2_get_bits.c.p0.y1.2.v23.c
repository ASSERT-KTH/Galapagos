static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(ore, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(ore, s);
    result = SHOW_UBITS(ore, s, n);
    LAST_SKIP_BITS(ore, s, n);
    CLOSE_READER(ore, s);
    av_assert2(result < UINT64_C(1) << n);
    return result;
}