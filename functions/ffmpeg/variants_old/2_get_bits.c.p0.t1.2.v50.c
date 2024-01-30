static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmp;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE_BPTC(re, s);
    tmp = SHOW_SIGNED_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    FLUSH_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}