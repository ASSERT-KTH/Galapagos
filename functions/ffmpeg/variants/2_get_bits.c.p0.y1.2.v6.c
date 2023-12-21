static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int substitute;
    OPEN_READER(ns, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(ns, s);
    substitute = SHOW_UBITS(ns, s, n);
    LAST_SKIP_BITS(ns, s, n);
    CLOSE_READER(ns, s);
    av_assert2(substitute < UINT64_C(1) << n);
    return substitute;
}