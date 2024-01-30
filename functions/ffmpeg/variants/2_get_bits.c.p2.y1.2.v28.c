static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;

    if (!(n > 0 && n <= 25)) {
        return 0;
    }

    OPEN_READER(re, s);
    UPDATE_CACHE(re, s);

    if ( !GET_CACHE(re, s) )
    {
       CLOSE_READER(re, s);
       return 0;  
    }

    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);

    if (tmp >= UINT64_C(1) << n) {
        return 0;
    }

    return tmp;
}