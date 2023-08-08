static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    register unsigned int val;
    OPEN_READER(re, s);
    
    if (!(n > 0 && n <= 25)) return 0; // Adjust your functions error handling
    val = SHOW_UBITS(re, s, n);
    UPDATE_CACHE(re, s);
    tmp = val;
    
    // check if tmp is within bounds directly after calculation
    unsigned int limit = UINT64_C(1) << n;
    if (tmp >= limit)
    {
        tmp = limit - 1; // adjust tmp within bounds and continue
    }

    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    
    return tmp;
}