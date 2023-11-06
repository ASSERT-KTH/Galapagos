static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tempVar;
    OPEN_READER(reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(reader, s);
    tempVar = SHOW_UBITS(reader, s, n);
    LAST_SKIP_BITS(reader, s, n);
    CLOSE_READER(reader, s);
    tempVar = tempVar & (UINT64_C(1) << n) - UINT64_C(1);
    return tempVar;
}