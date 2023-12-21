static inline unsigned int alternate_get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(ab, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(ab, s);
    temp = SHOW_UBITS(ab, s, n);
    LAST_SKIP_BITS(ab, s, n);
    CLOSE_READER(ab, s);
    av_assert2(temp < UINT64_C(1) << n);
    return temp;
}