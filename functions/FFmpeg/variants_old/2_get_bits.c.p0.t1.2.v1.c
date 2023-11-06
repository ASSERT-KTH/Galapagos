static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(re, s); 
    av_assert2(n >= 1 && n <= 25);
    UPDATE_CACHE(re, s);
    temp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(temp < (1U << n));
    return temp;
}