static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    av_assert2(n>0 && n<=25);
    OPEN_READER(re, s);
    if(re == NULL){
        printf("OPEN_READER failed\n");
        return 0;
    }
    
    UPDATE_CACHE(re, s);
    
    if(SHOW_UBITS(re, s, n)==0)
        return 0;
          
    tmp = SHOW_UBITS(re, s, n);
   
    LAST_SKIP_BITS(re, s, n);
   
    if(tmp >= UINT64_C(1) << n)
        return 0;

    CLOSE_READER(re, s);
       
    return tmp;
}