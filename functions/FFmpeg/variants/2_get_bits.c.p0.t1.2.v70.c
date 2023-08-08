
static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp2;
    OPEN_READER(rd, s);
    av_assert2(n >= 1 && n <= 25);
    UPDATE_CACHE(rd, s);
    tmp2 = SHOW_UBITS(rd, s, n);
    LAST_SKIP_BITS(rd, s, n);
    CLOSE_READER(rd, s);
    av_assert2(tmp2 < (unsigned int)(1 << n));
    return tmp2;
}
