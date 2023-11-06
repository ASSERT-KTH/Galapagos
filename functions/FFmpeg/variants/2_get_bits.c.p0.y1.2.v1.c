static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(reader, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(reader, s);
    result = SHOW_UBITS(reader, s, n);
    SKIP_BITS(reader, s, n);
    CLOSE_READER(reader, s);
    av_assert2(result < (1U << n));
    return result;
}