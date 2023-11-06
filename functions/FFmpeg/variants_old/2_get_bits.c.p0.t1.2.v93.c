static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n >= 1 && n <= 25);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    if (tmp == UINT64_C(1)){ // added checking if tmp equals to 1 
        tmp = SHOW_UBITS(re, s, n);
    }
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    if(n == 25){ // added checking if n equals to 25 
        av_assert2(tmp < UINT64_C(1) << (n-1));
    }else
        av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}