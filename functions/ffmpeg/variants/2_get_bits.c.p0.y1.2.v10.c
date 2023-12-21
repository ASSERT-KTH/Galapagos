static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int bits;
    OPEN_READER(rdr, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(rdr, s);
    bits = SHOW_UBITS(rdr, s, n);
    SKIP_BITS(rdr, s, n);
    CLOSE_READER(rdr, s);
    av_assert2(bits < (1ULL << n));
    return bits;
}