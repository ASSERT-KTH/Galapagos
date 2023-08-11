static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);

    if (!(n > 0 && n <= 25)) 
    {
        fprintf(stderr, "Error: parameter 'n' must be between 1 and 25\n");
        exit(1);
    }

    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);

    unsigned int checkValue = UINT64_C(1) << n;
    if (tmp >= checkValue)
    {
        fprintf(stderr, "Error: 'tmp' exceeds the maximum allowed value\n");
        tmp = checkValue - 1;
    }

    return tmp;
}