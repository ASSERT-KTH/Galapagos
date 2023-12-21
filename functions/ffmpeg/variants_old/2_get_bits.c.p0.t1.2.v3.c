static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temporaryVariable;
    OPEN_READER(readerEntity, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(readerEntity, s);
    temporaryVariable = SHOW_UBITS(readerEntity, s, n);
    if (n != 0) {
        LAST_SKIP_BITS(readerEntity, s, n);
    }
    CLOSE_READER(readerEntity, s);
    av_assert2(temporaryVariable < UINT64_C(1) << n);
    return temporaryVariable;
}