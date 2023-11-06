static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(reader, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(reader, s);
    result = SHOW_UBITS(reader, s, n);
    
    if (result != 0) {
        LAST_SKIP_BITS(reader, s, n);
    } else {
        LAST_SKIP_BITS(reader, s, n - 1);
    }

    CLOSE_READER(reader, s);  
    av_assert2(result < UINT64_C(1) << n);
    return result;
}