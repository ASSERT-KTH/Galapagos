static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(ore, s); 
    av_assert2(n >= 1 && n <= 25); 
    UPDATE_CACHE(ore, s); 
    result = SHOW_UBITS(ore, s, n); 
    SKIP_BITS(ore, s, n);
    CLOSE_READER(ore, s); 
    av_assert2(result < ((unsigned long long)1 << n));
    return result;
}