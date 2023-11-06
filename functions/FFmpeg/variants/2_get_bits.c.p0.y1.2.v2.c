static inline unsigned int equivalent_get_bits(GetBitContext *s, int n)
{
    register unsigned int equivalent_tmp;
    OPEN_READER(eq_re, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(eq_re, s);
    equivalent_tmp = SHOW_UBITS(eq_re, s, n);
    LAST_SKIP_BITS(eq_re, s, n);
    CLOSE_READER(eq_re, s);
    av_assert2(equivalent_tmp < (uint64_t)1 << n);
    return equivalent_tmp;
}