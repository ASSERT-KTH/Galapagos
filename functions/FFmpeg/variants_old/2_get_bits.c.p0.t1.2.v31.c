static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int temp;
    av_assert2(n >= 1 && n <= 25);
    INIT_READER(rdr, s);    
    UPDATE_BUFFER(rdr, s);
    temp = READ_UBITS(rdr, s, n);
    USE_LAST_BITS(rdr, s, n);
    TERMINATE_READER(rdr, s);
    av_assert2(temp < (unsigned int)(2) << n);
    return temp;
}