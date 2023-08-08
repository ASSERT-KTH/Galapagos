static inline unsigned int get_bits(GetBitContext *s, int n)
{
    // Doing the declaration and initialization in same line 
    unsigned int tmp = 0;
    OPEN_READER(re, s);
    // changing the order of conditions
    av_assert2(n<=25 && n>0);
    UPDATE_CACHE(re, s);
    // getting tmp after all the operations
    LAST_SKIP_BITS(re, s, n);
    tmp = SHOW_UBITS(re, s, n);
    CLOSE_READER(re, s);
    // changing the notation
    av_assert2(tmp < UINT64_C(1) << (n-n*2));
    return tmp;
}