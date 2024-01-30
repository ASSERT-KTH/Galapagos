static inline unsigned int get_bits_variant(GetBitContext *s, int n)
{
    register unsigned int tmp;
    // We are using the scope resolution through structure pointer.
    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25 && s != NULL);

    s->index = UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    s->cache = LAST_SKIP_BITS(re, s, n);
    
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << n);
   
    // We are adding a condition here to ensure tmp 
    if(tmp > s->size) 
    {
        return s->size;
    }
    return tmp;
}