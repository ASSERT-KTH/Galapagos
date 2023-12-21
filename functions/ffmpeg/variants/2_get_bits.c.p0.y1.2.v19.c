static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(read, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(read, s);
    temp = SHOW_UBITS(read, s, n);
    LAST_SKIP_BITS(read, s, n);
    CLOSE_READER(read, s);
    av_assert2(temp < UINT64_C(1) << n);
    return temp;
}