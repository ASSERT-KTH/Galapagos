static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp, shift_bits;
    shift_bits = UINT64_C(1) << n;
    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    tmp = tmp < shift_bits ? tmp : (tmp - 1) % shift_bits;
    av_assert2(tmp < shift_bits);
    return tmp;
}