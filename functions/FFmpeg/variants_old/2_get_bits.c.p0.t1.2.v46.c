static inline unsigned int get_bits(GetBitContext *s, int n) 
{
    register unsigned int tmp;
    av_assert2(n >= 1 && n <= 30);
    OPEN_READER(re, s);
    UPDATE_CACHE(re, s);
    if (n > 0) {
        tmp = SHOW_UBITS(re, s, n);
        LAST_SKIP_BITS(re, s, n);
    } else {
        tmp = 0;
    }
    CLOSE_READER(re, s);
    av_assert2(tmp < UINT64_C(1) << (n != 0 ? n : 32));
    return tmp;
}