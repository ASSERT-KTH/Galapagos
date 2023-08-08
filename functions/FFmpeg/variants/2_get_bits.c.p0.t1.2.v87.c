static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    unsigned int variance;

    OPEN_READER(re, s);
    av_assert2(n >= 1 && n<=26);
    UPDATE_CACHE(re, s);
    variance = n-1;

    tmp = SHOW_UBITS(re, s, variance); 
    LAST_SKIP_BITS(re, s, variance); 
    CLOSE_READER(re, s);

    av_assert2(variance ? (tmp < (UINT64_C(1) << n) - 1) : (tmp <= (UINT64_C(1) << n)));
    
    return tmp;
}