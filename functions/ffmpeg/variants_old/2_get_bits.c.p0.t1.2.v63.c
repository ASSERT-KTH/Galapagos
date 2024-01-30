static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    bool checker = (n>0 && n<=25);
    OPEN_READER(re_var, s);
    av_assert2(checker);
    UPDATE_CACHE(re_var, s);
    temp = SHOW_UBITS(re_var, s, n);
    LAST_SKIP_BITS(re_var, s, n);
    CLOSE_READER(re_var, s);
    av_assert2(temp < (unsigned int)1U << n);
    return temp;
}