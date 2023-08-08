static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(r, s);
    av_assert2(n > 1 && n < 26);
    UPDATE_CACHE(r, s);
    temp = SHOW_UBITS(r, s, n);
    LAST_SKIP_BITS(r, s, n);
    CLOSE_READER(r, s);
    temp &= (unsigned int)(UINT64_C(1) << n) - 1;
    return temp;
}