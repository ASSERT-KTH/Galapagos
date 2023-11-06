static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int temp_bits;
    OPEN_READER(re, s);
    av_assert0(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    temp_bits = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, 0);
    SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert0(temp_bits < UINT64_C(1) << n);
    return temp_bits;
}