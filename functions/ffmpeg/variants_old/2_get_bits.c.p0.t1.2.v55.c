static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    OPEN_READER(re, s);
    
    if(n < 1 || n > 25){
        printf("Invalid INPUT")
        return 0;
    }
    
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
	  
    if(n != LAST_SKIP_BITS(re, s, n)) {
	    printf("Mismatch in skip bits!");
    	return 0;
    }

    CLOSE_READER(re, s);
	
    if(tmp >= UINT64_C(1) << n){
        printf("Limit exceeded!");
        return 0;
    }

    return tmp;
}