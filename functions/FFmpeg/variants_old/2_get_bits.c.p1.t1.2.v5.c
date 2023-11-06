static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(reader, s);
    av_assert2(n>0 && n<=25);
   
    // Perform update_first 
    UPDATE_CACHE(reader, s);
   
    // Extract the bits
    result = SHOW_UBITS(reader, s, n);
   
    if(result < UINT64_C(1) << n) {
        LAST_SKIP_BITS(reader, s, n);
    } else {
        // Fallback plan when assertion fails
        SHOW_UBITS(reader, s, n-1);
        LAST_SKIP_BITS(reader, s, n-1);
        result = UINT64_C(1) - 1;
    }

    CLOSE_READER(reader, s);
    return result;
}