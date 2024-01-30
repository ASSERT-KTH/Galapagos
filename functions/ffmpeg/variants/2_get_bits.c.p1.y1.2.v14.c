Variant 1

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;    
    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25);    
    UPDATE_CACHE(re, s);    
    LAST_SKIP_BITS(re, s, n);    
    tmp = SHOW_UBITS(re, s, n);    
    CLOSE_READER(re, s);    
    av_assert2(tmp < UINT64_C(1) << n);    
    return tmp;
}


Variant 2

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25);    
    UPDATE_CACHE(re, s);    
    register unsigned int tmp = SHOW_UBITS(re, s, n);    
    LAST_SKIP_BITS(re, s, n);    
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << n);  
    return tmp;
}


Variant 3

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    av_assert2(n > 0 && n <= 25);    
    OPEN_READER(re, s);
    update_cache(re, s);    
    register unsigned int tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);    
    close_reader(re, s);
    av_assert2(tmp < UINT64_C(1) << n);    
    return tmp;
}


Variant 4

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    OPEN_READER(re, s);    
    UPDATE_CACHE(re, s);
    av_assert2(n > 0 && n <= 25);        
    register unsigned int tmp = SHOW_UBITS(re, s, n);    
    LAST_SKIP_BITS(re, s, n);
    av_assert2(tmp < UINT64_C(1) << n);  
    CLOSE_READER(re, s);    
    return tmp;
}
