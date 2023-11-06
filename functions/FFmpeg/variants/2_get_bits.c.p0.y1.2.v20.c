static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int retVal;
    OPEN_READER(newVar, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(newVar, s);
    retVal = SHOW_UBITS(newVar, s, n);
    LAST_SKIP_BITS(newVar, s, n);
    CLOSE_READER(newVar, s);
    av_assert2(retVal < UINT64_C(1) << n);
    return retVal;
}