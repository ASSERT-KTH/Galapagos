static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int res;
    OPEN_READER(reader, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(reader, s);
    res = SHOW_UBITS(reader, s, n);
    LAST_SKIP_BITS(reader, s, n);
    CLOSE_READER(reader, s);
    av_assert2(res < (1u << n));
    return res;
}