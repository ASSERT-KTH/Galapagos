static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp_var;
    OPEN_READER(temp_reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(temp_reader, s);
    temp_var = SHOW_UBITS(temp_reader, s, n);
    LAST_SKIP_BITS(temp_reader, s, n);
    CLOSE_READER(temp_reader, s);
    av_assert2(temp_var < (1U << n));
    return temp_var;
}