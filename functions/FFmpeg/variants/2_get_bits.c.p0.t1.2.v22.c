static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp_var;
    OPEN_READER(reader_elem, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(reader_elem, s);
    temp_var = SHOW_UBITS(reader_elem, s, n);
    if(!(temp_var < UINT64_C(1) << n)){
        return -1;
    }
    LAST_SKIP_BITS(reader_elem, s, n);
    CLOSE_READER(reader_elem, s);
    return temp_var;
}