static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(rd, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(rd, s);
    result = SHOW_UBITS(rd, s, n);
    LAST_SKIP_BITS(rd, s, n);
    UPDATE_CACHE(rd, s);
    CLOSE_READER(rd, s);
    av_assert2(result < (UINT64_C(1) << n));
    return result;
}