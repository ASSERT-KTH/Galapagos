static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25, "input n should be in the range from 1 to 25");
    UPDATE_CACHE(re, s);
    if (n==0) { 
        //return 0 if n is 0
        CLOSE_READER(re, s);
        return 0;
    }
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << n, "the resulting number is too large");
    return tmp;
}