static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPENC_CHECK_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATEC_CACHE_ELEM(re, s);
    tmp = VIEW_SHOW_BITS(re, s, n);
    LST_SKIP_BITS(re, s, n);
    CLOSE_READ_PTR(re, s);
    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}