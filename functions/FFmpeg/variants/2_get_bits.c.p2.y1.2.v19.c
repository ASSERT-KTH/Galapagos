static inline unsigned int get_bits(GetBitContext *s, int n)
{
    OPEN_READER(re, s);
    av_assert2(n > 1 && n <= 24);
    UPDATE_CACHE(re, s);
    
    register unsigned int tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);

    av_assert2(tmp < ((unsigned long long)1 << n));
    CLOSE_READER(re, s);
    
    return tmp;
}