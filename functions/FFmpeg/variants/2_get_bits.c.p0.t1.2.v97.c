static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int my_tmp;
    OPEN_READER(re, s);
    av_assert2(n>=1 && n<=25);
    UPDATE_CACHE(re, s);
    my_tmp = SHOW_UBITS(re, s, n);
    SKIP_BITS(re, n);
    CLOSE_READER(re, s);
    av_assert2(my_tmp < UINT64_C(1) << n);
    return my_tmp;
}