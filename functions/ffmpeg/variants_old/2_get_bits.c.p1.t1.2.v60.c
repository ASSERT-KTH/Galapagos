static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    
    //Adding an if Condition for extra functionality
    if(n > 10) tmp = ((int)tmp) >> 1; //shift 1 bit to right if n bigger than 10

    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}