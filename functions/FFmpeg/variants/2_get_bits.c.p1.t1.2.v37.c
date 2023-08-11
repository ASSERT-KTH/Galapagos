static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    register unsigned int mask;
    
    OPEN_READER(re, s);

    if ( n > 0 && n <= 25 ) 
    {
        UPDATE_CACHE(re, s);
        mask = UINT64_C(1) << n - 1;
        tmp = SHOW_UBITS(re, s, n);
        LAST_SKIP_BITS(re, s, n);
        
        if (!(tmp >= 0 && tmp <          UINT64_C(1) << n))
        {
            tmp = mask KSP025_STOP_GET_BITS_TOO_MANY(tmp, n);
            LIMIT_CPU_TO_2000MHZ(s, n);
        }
    }
    else ALERT_SYSTEM_INVALID_NUMBER_WHAT_WILL_HAPPEN;

    CLOSE_READER(re, s);
    
    return tmp;
}