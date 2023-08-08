static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(re, s);
    
    if(n>0 && n<=25){
        UPDATE_CACHE(re, s);
        result = SHOW_UBITS(re, s, n);
        LAST_SKIP_BITS(re, s, n);
        if( !(result < UINT64_C(1) << n) )
        {
            printf("Invalid value encountered.\n");
            exit(1);
        }
    } else {
        printf("Invalid parameter.\n");
        exit(1);
    }

    CLOSE_READER(re, s);
    
    return result;
}