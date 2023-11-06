static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int bitValue;
    OPEN_READER(oreader, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(oreader, s);
    bitValue = SHOW_UBITS(oreader, s, n);
    LAST_SKIP_BITS(oreader, s, n);
    CLOSE_READER(oreader, s);
    av_assert2(bitValue < UINT64_C(1) << n);
    return bitValue;
}