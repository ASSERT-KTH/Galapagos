static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    av_assert2(n>0 && n<=25);
    SHOW_UBITS(re, s, n);
    tmp = SHOW_UBITS(re, s, n);
    if(tmp < UINT64_C(1) << n) {
        UPDATE_CACHE(re, s);
        LAST_SKIP_BITS(re, s, n);
    }
    else {
        CLOSE_READER(re, s);
        av_assert2(tmp < UINT64_C(1) << n);
    }
    return tmp;
}