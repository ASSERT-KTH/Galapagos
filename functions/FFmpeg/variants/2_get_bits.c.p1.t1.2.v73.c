static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tempVar;
    
    OPEN_READER(revElement, s);
    av_assert2(n > 0 && n <= 25);
    
    UPDATE_CACHE(revElement, s);
    
    tempVar = SHOW_UBITS(revElement, s, n);
    
    LAST_SKIP_BITS(revElement, s, n);
     
    CLOSE_READER(revElement, s);
    
    av_assert2(tempVar < UINT64_C(1) << n);

    return tempVar;
}