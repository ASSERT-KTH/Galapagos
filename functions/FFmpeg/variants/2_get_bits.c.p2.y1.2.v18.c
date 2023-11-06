static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp_var;
    OPEN_READER(to_read, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(to_read, s);
    temp_var = SHOW_UBITS(to_read, s, n);
    if(!(temp_var < UINT64_C(1) << n)){
        return 0;
    }
    LAST_SKIP_BITS(to_read, s, n);
    CLOSE_READER(to_read, s);
    return temp_var;
}