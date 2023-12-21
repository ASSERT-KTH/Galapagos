Here's a variant of the function. It doesn't alter the original function's behavior as such but just reorder the instructions for the sake of readability and optimization:


static inline unsigned int get_bits(GetBitContext *s, int n)
{
    
    av_assert2(n > 0 && n <= 25);
    register unsigned int tmp;
    OPEN_READER(re, s);
    
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
  
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);

    av_assert2(tmp < (unsigned int)1 << n);

    return tmp;
}
