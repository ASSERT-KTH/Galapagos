static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);

    // Make assert checks optional by surrounding it with #ifdef DEBUG flag
    #ifdef DEBUG
    av_assert2(n>0 && n<=25);
    #endif

    UPDATE_CACHE(re, s);

    // Switch the order of LAST_SKIP_BITS 
    LAST_SKIP_BITS(re, s, n);
    tmp = SHOW_UBITS(re, s, n);

    CLOSE_READER(re, s);

    #ifdef DEBUG
    av_assert2(tmp < UINT64_C(1) << n);
    #endif

    return tmp;
}