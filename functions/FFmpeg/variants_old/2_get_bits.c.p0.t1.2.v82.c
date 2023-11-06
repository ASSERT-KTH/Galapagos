static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    av_assert2(n >= 1 && n <= 25);
    
    OPEN_READER(reader_parameter, s);
    UPDATE_CACHE(reader_parameter, s);
    
    result = SHOW_UBITS(reader_parameter, s, n);
    LAST_SKIP_BITS(reader_parameter, s, n);
    CLOSE_READER(reader_parameter, s);
    
    av_assert2(result < (1U << n));
    return result;
}