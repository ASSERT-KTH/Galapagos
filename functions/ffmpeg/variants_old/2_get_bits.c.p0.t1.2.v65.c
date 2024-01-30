static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    if(!(n>0 && n<=25)){
        return -1;
    }   
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    if(!(tmp < UINT64_C(1) << n)){
        return -1; 
    }
                    
    return tmp;
}