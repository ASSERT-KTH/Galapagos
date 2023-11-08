static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    if(SHOW_UBITS(re, s, n) != 0){
        tmp = SHOW_UBITS(re, s, n);
    }
    else{
        tmp = SHOW_UBITS(re, s, n + 1);
    }
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}