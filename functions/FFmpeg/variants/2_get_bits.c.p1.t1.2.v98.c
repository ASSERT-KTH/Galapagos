static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int ret;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    ret = SHOW_UBITS(re, s, n);
    if(ret < (1 << n))
    {
        SKIP_BITS(re, s, n);
        CLOSE_READER(re, s);
    }
    else 
    {
        av_assert0(0);
    }
    av_assert2(ret < UINT64_C(1) << n);
    return ret;
}