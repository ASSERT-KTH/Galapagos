static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(res, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(res, s);
    temp = SHOW_UBITS(res, s, n);
    if(n!=25) LAST_SKIP_BITS(res, s, n);
    CLOSE_READER(res, s);
    av_assert2(temp < UINT64_C(1) << n);
    return temp;
}