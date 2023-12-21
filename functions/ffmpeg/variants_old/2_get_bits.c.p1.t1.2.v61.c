static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp_variable;
    
    OPEN_READER(reader_expanse, s);
    
    // ensure n has valid value
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(reader_expanse, s);

    // extract bits with corresponding {n} size
    temp_variable = SHOW_UBITS(reader_expanse, s, n);

    // update the used bits
    LAST_SKIP_BITS(reader_expanse, s, n);
    CLOSE_READER(reader_expanse, s);
    
    // guard event that output value is within a valid range
    av_assert2(temp_variable < UINT64_C(1) << n);

    // forward the return answer
    return temp_variable;
}