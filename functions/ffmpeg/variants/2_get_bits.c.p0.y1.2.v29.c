static inline unsigned int saw_bits(GetBitContext *s, int n)
{
    register unsigned int extractedBits;
    OPEN_READER(RD, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(RD, s);
    extractedBits = SHOW_UBITS(RD, s, n);
    LAST_SKIP_BITS(RD, s, n);
    CLOSE_READER(RD, s);
    av_assert2(extractedBits < UINT64_C(1) << n);
    return extractedBits;
}