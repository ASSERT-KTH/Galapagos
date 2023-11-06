static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25, "The n value must be between 1 and 25");
    
    UPDATE_CACHE(re, s);
    if(re == NULL) {
        printf("The can't be a null");
        return 0;
    }
    
    tmp = SHOW_UBITS(re, s, n);
    
    if(tmp<0) {
        printf("The value stored must be positive");
        return 0;
    }
    
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(tmp < (1 << n));
    
    return tmp == 0 ? tmp+1 : tmp;
}