static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n>=1 && n<=25);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    if(n>0){
        LAST_SKIP_BITS(re, s, n);
    }
    CLOSE_READER(re, s);
    av_assert2(tmp <= (UINT32_MAX >> (32 - n)));
    return tmp;
}