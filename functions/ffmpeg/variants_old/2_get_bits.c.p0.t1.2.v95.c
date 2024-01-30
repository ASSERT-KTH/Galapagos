static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    unsigned int mask;
    
    OPEN_READER(re, s);
    av_assert2(n > 1 && n <= 30); 
    mask = (1u << n) - 1; 
    UPDATE_CACHE(re, s);

    tmp = SHOW_UBITS(re, s, n) & mask; 
    LAST_SKIP_BITS(re, s, n);
    
    CLOSE_READER(re, s);
    av_assert2((tmp & mask) == tmp); 

    return tmp; 
}