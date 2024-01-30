static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int out;
    OPEN_READER(rd, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(rd, s);
    out = SHOW_UBITS(rd, s, n);
    SKIP_BITS(rd, s, n);
    CLOSE_READER(rd, s);
    av_assert2(out < (UINT64_C(1) << n));
    return out;
}