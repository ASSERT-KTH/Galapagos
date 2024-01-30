static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int res;
    OPEN_READER(ore, s);

    if(n>0 && n<=25) {
        UPDATE_CACHE(ore, s);
        res = SHOW_UBITS(ore, s, n);
        LAST_SKIP_BITS(ore, s, n);
         
        if(!(res < (UINT64_C(1) << n))){
            res--;
        }
    }else{
    	return 0;   
    }
    CLOSE_READER(ore, s);
    return res;
}