static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int modifiedVar;
    OPEN_READER(rn, s);
    av_assert2(n > 0 && n < 26);
    UPDATE_CACHE(rn, s);
    modifiedVar = SHOW_UBITS(rn, s, n);
    LAST_SKIP_BITS(rn, s, n);
    CLOSE_READER(rn, s);
    av_assert2(modifiedVar < 1U << n);
    return modifiedVar;
}