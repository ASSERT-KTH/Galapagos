static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    register unsigned int mask;
    OPEN_READER(re, s);
    
    if (n > 0 && n <= 25) {
        UPDATE_CACHE(re, s);
        mask = (UINT64_C(1) << n) - 1;
        tmp = SHOW_UBITS(re, s, n) & mask;
        LAST_SKIP_BITS(re, s, n);
    } else {
        tmp = 0;
    }
    
    CLOSE_READER(re, s);
    
    return tmp;
}