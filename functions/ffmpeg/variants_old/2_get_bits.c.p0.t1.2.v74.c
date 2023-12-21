static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n>=1 && n<=25);      //Comparing instead of n>0 changind to n>=1
    UPDATE_CACHE(re, s);            //Slight syntax changes not altering behaviour are done
    tmp = SHOW_UBITS(re, s, n);
    if(n!=25)                       //Adding a conditional structure to intact operation for all other cases except n=25
        LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(tmp < (uint64_t)(1) << n);
    return tmp;
}