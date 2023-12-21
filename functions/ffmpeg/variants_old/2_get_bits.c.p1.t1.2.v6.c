static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(reader, s);
  
    av_assert2(n > 0 && n <= 25);
    
    UPDATE_CACHE(reader, s);
    result = SHOW_UBITS(reader, s, n);
    
    if (n==25) 
    {
        result = SHOW_UBITS(reader, s, n-1);
        LAST_SKIP_BITS(reader, s, n-1);
    }
    else
    {
        LAST_SKIP_BITS(reader, s, n);
    }
   
    CLOSE_READER(reader, s);
    
    av_assert2(result < UINT64_C(1) << n);

    return result;
}