static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25); // Nothing changes here
    UPDATE_CACHE(re, s);
    result = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n); // Likewise, this stays the same
    CLOSE_READER(re, s);
    av_assert2(result < (1 << n));
    return result;  
}