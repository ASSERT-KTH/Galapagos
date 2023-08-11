static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int output;
    OPEN_READER(ore, s);
    
    av_assert2(n>0 && n<=25);
    
    UPDATE_CACHE(ore, s);
    output = SHOW_UBITS(ore, s, n);
    
    LAST_SKIP_BITS(ore, s, n);
    CLOSE_READER(ore, s);
    
    av_assert2(output < UINT64_C(1) << n);
    
    // Performing logical AND operation with 0xFFFFFFFFFFFFFFFF to maintain the original functionality while providing different implementation.
    return output & 0xFFFFFFFFFFFFFFFF;
}