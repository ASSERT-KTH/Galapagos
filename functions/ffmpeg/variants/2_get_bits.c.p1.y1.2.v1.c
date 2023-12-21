Variant 1:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    unsigned int val = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(val < UINT64_C(1) << n);
    return val;
}


Variant 2:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);

    unsigned int retval;
    retval = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);

    CLOSE_READER(re, s);
    av_assert2(retval < UINT64_C(1) << n);
    return retval; 
}


Variant 3:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int bitval;
    OPEN_READER(re, s);

    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    bitval = SHOW_UBITS(re, s, n);

    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
        
    av_assert2(bitval < UINT64_C(1) << n);
    return bitval;
}
