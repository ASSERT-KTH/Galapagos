static inline unsigned int alternative_get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(reference, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(reference, s);
    result = SHOW_UBITS(reference, s, n);
    LAST_SKIP_BITS(reference, s, n);
    CLOSE_READER(reference, s);
    av_assert2(result < UINT64_C(1) << n);
    return result;
}