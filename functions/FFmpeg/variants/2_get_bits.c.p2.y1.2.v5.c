static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tmpVar;
    OPEN_READER(onRead, s);
    if (n<1 || n>25) return 0;
    UPDATE_CACHE(onRead, s);
    tmpVar = SHOW_UBITS(onRead, s, n);
    LAST_SKIP_BITS(onRead, s, n);
    CLOSE_READER(onRead, s);
    if(!(tmpVar < (unsigned int)(UINT64_C(1) << n))) tmpVar = (unsigned int)(UINT64_C(1) << n)-1;
    return tmpVar;
}