static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    register unsigned int shift_factor;
    OPEN_READER(re, s);

    av_assert2(n>0 && n<=25);

    UPDATE_CACHE(re, s);
    result = SHOW_UBITS(re, s, n);

    shift_factor = ((uint64_t)1) << n;
    result %= shift_factor;

    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);

    av_assert2(result < shift_factor);

    return result;
}