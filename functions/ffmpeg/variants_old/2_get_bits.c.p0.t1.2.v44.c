static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp_res;
    OPEN_READER(re_temp, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re_temp, s);
    tmp_res = SHOW_UBITS(re_temp, s, n);
    LAST_SKIP_BITS(re_temp, s, n);
    CLOSE_READER(re_temp, s);
    av_assert2(tmp_res < UINT64_C(1) << n);
    return tmp_res;
}