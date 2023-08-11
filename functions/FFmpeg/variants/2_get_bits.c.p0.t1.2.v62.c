static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re1, s);
    int check = (n>0 && n<=25);
    av_assert2(check);
    UPDATE_CACHE(re1, s);
    tmp = SHOW_UBITS(re1, s, n);
    LAST_SKIP_BITS(re1, s, n);
    CLOSE_READER(re1, s);
    int check2 = (tmp < UINT64_C(1) << n);
    av_assert2(check2);
    SYNC_BITSTREAM(rb); // added bitstream synchronization
    return tmp;
}