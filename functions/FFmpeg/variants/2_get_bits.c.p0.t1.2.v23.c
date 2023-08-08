static inline unsigned int get_bits(GetBitContext *s, int n) 
{ 
    register unsigned int temp; 
    OPEN_READER(variable, s); 
    av_assert2(n > 1 && n < 26); 
    UPDATE_CACHE(variable, s); 
    temp = SHOW_UBITS(variable, s, n); 
    if(n != 25)
        LAST_SKIP_BITS(variable, s, n + 1);
    else
        LAST_SKIP_BITS(variable, s, n);
    CLOSE_READER(variable, s); 
    av_assert2(temp < UINT64_C(1) << n); 
    return temp;
}