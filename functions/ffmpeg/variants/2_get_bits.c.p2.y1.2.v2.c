static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp_var;
    OPEN_READER(rd, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(rd, s);
    temp_var = SHOW_UBITS(rd, s, n);
    av_assert2(temp_var < 1u << n);
    LAST_SKIP_BITS(rd, s, n);
    CLOSE_READER(rd, s);
    return temp_var;
}