static inline unsigned int get_bits(GetBitContext *s, int n) 
{
    unsigned int temporaryValue;
    OPEN_READER(registerValue, s);

    if (!(n > 0 && n <= 25)) 
        return 0;

    UPDATE_CACHE(registerValue, s);

    temporaryValue = SHOW_UBITS(registerValue, s, n);
    LAST_SKIP_BITS(registerValue, s, n);

    CLOSE_READER(registerValue, s);

    if (!(temporaryValue < UINT64_C(1) << n)) 
        return 0;
		
    return temporaryValue;
}