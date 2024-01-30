static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    int secondary_n = n;
    OPEN_READER(r_ex, s);
    av_assert2(secondary_n > 0 && secondary_n <= 25);
    UPDATE_CACHE(r_ex, s);
    tmp = GET_CACHE(r_ex, s);
    SKIP_CACHE(r_ex, s, secondary_n);
    CLOSE_READER(r_ex, s);
    av_assert2(tmp < UINT64_C(1) << secondary_n);
    return tmp;
}