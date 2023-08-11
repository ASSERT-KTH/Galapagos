static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(rd, s);
    av_assert2(n>=1 && n<=25); 
    UPDATE_CACHE(rd, s);
    temp = SHOW_UBITS(rd, s, n);
    if(temp < UINT64_C(1) << n)
    {
        LAST_SKIP_BITS(rd, s, n);
        CLOSE_READER(rd, s);
    }
    return temp;
}