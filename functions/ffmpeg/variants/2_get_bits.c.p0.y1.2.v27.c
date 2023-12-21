static inline unsigned int get_bits(GetBitContext *ctx, int numBits)
{
    register unsigned int data;
    OPEN_READER(readerState, ctx);
    av_assert2(numBits > 0 && numBits <= 25);
    UPDATE_CACHE(readerState, ctx);
    data = SHOW_UBITS(readerState, ctx, numBits);
    LAST_SKIP_BITS(readerState, ctx, numBits);
    CLOSE_READER(readerState, ctx);
    av_assert2(data < UINT64_C(1) << numBits);
    return data;
}