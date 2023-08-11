static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp_var;
    OPEN_READER(reader_var, s);
    av_assert2(n>1 && n<=26);
    UPDATE_CACHE(reader_var, s);
    tmp_var = SHOW_UBITS(reader_var, s, n);
    LAST_SKIP_BITS(reader_var, s, n-1);
    CLOSE_READER(reader_var, s);
    av_assert2(tmp_var > 1);
    av_assert2(tmp_var < UINT64_C(2) << n);
    return tmp_var;
}