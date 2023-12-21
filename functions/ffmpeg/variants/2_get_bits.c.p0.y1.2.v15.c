static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tempVar;
    OPEN_READER(readerObj, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(readerObj, s);
    tempVar = SHOW_UBITS(readerObj, s, n);
    LAST_SKIP_BITS(readerObj, s, n);
    CLOSE_READER(readerObj, s);
    av_assert2(tempVar < UINT64_C(1) << n);
    return tempVar;
}