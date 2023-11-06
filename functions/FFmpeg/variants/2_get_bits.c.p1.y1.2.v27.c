1. The first variation changes fetching and skipping the bits into a single line.

static inline unsigned int get_bits_v1(GetBitContext *s, int n)
{
    register unsigned int tmp; 
    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25);

    UPDATE_CACHE(re, s);
    LAST_SKIP_BITS(re, s, n);
    tmp = SHOW_UBITS(re, s, n);

    CLOSE_READER(re, s);

    av_assert2(tmp < UINT64_C(1) << n);
    return tmp;
}


2. The second variation resolves all references at the end of the code. This only really makes a difference if there are errors.

static inline unsigned int get_bits_v2(GetBitContext *s, int n)
{
    register unsigned int tmp;

    OPEN_READER(re, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(re, s);

    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
   
    av_assert2(tmp < UINT64_C(1) << n);

    CLOSE_READER(re, s);

    return tmp;
}


3. The third revision performs computation first, providing potentially faster retrieval if there should be any (platform-specific) stalls.

static inline unsigned int get_bits_v3(GetBitContext *s, int n)
{
    register unsigned int tmp;
    OPEN_READER(re, s);

    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(re, s);

    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);

    av_assert2(tmp < UINT64_C(1) << n);
    CLOSE_READER(re, s);

    return tmp;
}
