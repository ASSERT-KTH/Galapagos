static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    tmp = SHOW_UBITS(re, s, n);
    if(n>=1 && n<=25) {av_assert2(n>0 && n<=25);}
    else return UINT64_C(1);
    UPDATE_CACHE(re, s);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}