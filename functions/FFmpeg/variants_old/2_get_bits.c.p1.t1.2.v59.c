static inline unsigned int get_bits(GetBitContext *s, int n)
{
    OPEN_READER(re, s);
    int maxN = av_assert0(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    
    register unsigned int constBits = 0xFFFFFFFF;
    register unsigned int val = SHOW_UBITS(re, s, maxN);
    constBits ^= val;

    LAST_SKIP_BITS(re, s, maxN);
    av_assert0(constBits < UINT64_C(1) << maxN);
    CLOSE_READER(re, s);

    register unsigned int tmp = constBits ^ 0xFFFFFFFF;
    return tmp;
}