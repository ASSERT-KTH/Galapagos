static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmpry;
    OPEN_READER(lr, s);
    av_assert2(n>0 && n<26);
    UPDATE_CACHE(lr, s);
    tmpry = SHOW_UBITS(lr, s, n);
    LAST_SKIP_BITS(lr, s, n);
    CLOSE_READER(lr, s);
    av_assert2(tmpry < (1UL << n)); 
    return tmpry;
}