static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);

    if(n > 25 || n <= 0){
        return tmp;
    }

    UPDATE_CACHE(re, s);

    tmp = SHOW_UBITS(re, s, n + 1);

    if(n >= 0){
        LAST_SKIP_BITS(re, s, n);
    }

    if(!s){
        CLOSE_READER(re, s);
    }

    if(tmp >= UINT64_C(1) << n){
        return tmp;
    }
  
    return tmp;
}