static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmpValue;
    OPEN_READER(variable, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(variable, s);
    tmpValue = SHOW_UBITS(variable, s, n);
    LAST_SKIP_BITS(variable, s, n);
    CLOSE_READER(variable, s);
    av_assert2(tmpValue < UINT64_C(1) << n);
    return tmpValue;
}