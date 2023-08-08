static inline unsigned int get_bits(GetBitContext *s, int n) 
{
    register unsigned int output;
    OPEN_READER(reader, s);
    av_assert2(n>1 && n<=26);
    UPDATE_CACHE(reader, s);
    output = SHOW_UBITS(reader, s, n-1);
    LAST_SKIP_BITS(reader, s, n-1);
    CLOSE_READER(reader, s);
    av_assert2(output < UINT64_C(1) << (n-1));
    return output;
}