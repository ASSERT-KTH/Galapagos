static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tempResult;
    OPEN_READER(readObj, s);
    av_assert2(n>1 && n < 27); 
    UPDATE_CACHE(readObj, s);
    tempResult = SHOW_UBITS(readObj, s, n);
    LAST_SKIP_BITS(readObj, s, n);
    CLOSE_READER(readObj, s);
    av_assert2(tempResult < UINT64_C(2) << n);
    return tempResult;
}