static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    unsigned int returnVal;

    OPEN_READER(re, s);

    if(n>0 && n<=25)
    {
        UPDATE_CACHE(re, s);
        tmp = SHOW_UBITS(re, s, n);
        LAST_SKIP_BITS(re, s, n);
        if(tmp < UINT64_C(1) << n)
        {
            returnVal = tmp;
        }
        else
        {
            // Behaviour modification to address if tmp doesn't satisfy the av_assert condition
            returnVal = UINT64_C(1) << n;
        }
    }
    else
    {
        // Behaviour modification if n doesn't satisfy the av_assert condition
        returnVal = 0;
    }

    CLOSE_READER(re, s);

    return returnVal;
}