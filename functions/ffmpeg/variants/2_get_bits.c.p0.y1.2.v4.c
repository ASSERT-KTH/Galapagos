static inline unsigned int alternate_get_bits(GetBitContext *s, int n)
{
    register unsigned int returnedBit;
    BEGIN_READER(br, s);
    av_assert2(n>0 && n<=25);
    REFILL_CACHE(br, s);
    returnedBit = DISPLAY_UBITS(br, s, n);
    CONTINUE_SKIP_BITS(br, s, n);
    END_READER(br, s);
    av_assert2(returnedBit < UINT64_C(1) << n);
    return returnedBit;
}