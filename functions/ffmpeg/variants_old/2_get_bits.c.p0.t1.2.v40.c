static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n >= 1 && n <= 25); // Modified condition check
    UPDATE_CACHE(re, s);
    GET_CACHE(re, s);  // Used different approach to get cache
    tmp = GET_BITS(re, s, n);  // Different methodology used which is bitwise approach
    SKIP_BITS(re, s, n); // Moved to next bit 
    CLOSE_READER(re, s);
    av_assert2(tmp < (1U << n));   // Alternative way to do shift and compare
    return tmp;
}