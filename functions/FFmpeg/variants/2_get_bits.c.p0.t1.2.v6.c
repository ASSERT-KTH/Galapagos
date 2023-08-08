static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp_var;
    OPEN_READER(rdvar, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(rdvar, s);
    temp_var = SHOW_UBITS(rdvar, s, n);
    LAST_SKIP_BITS(rdvar, s, n);
    CLOSE_READER(rdvar, s);
    av_assert2(temp_var < UINT64_C(1) << n || temp_var == 0);
    return temp_var;
}