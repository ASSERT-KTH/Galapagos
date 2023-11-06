static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    register unsigned int final;
    OPEN_READER(r1, s);
    av_assert2(n > 0 && n<30);
    UPDATE_CACHE(r1, s);
    tmp = SHOW_UBITS(r1, s, n);
    LAST_SKIP_BITS(r1, s, n);
    CLOSE_READER(r1, s);
    final = tmp % UINT32_MAX;
    av_assert2(final <= UINT32_C(1) << n);
    return final;
}