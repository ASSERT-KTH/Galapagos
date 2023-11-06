// Variant 1:
static inline unsigned int get_bits(GetBitContext *s, int n)
{
    unsigned int tempVar;
    OPEN_READER(readerElement, s);

    av_assert2(n > 0 && n <= 25);

    UPDATE_CACHE(readerElement, s);
    tempVar = SHOW_UBITS(readerElement, s, n);

    LAST_SKIP_BITS(readerElement, s, n);
    CLOSE_READER(readerElement, s);

    av_assert2(tempVar < UINT64_C(1) << n);

    return tempVar;
}

// Variant 2:
static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp;
    OPEN_READER(rE, s);

    av_assert2(n > 0 && n <= 25);

    UPDATE_CACHE(rE, s);
    temp = SHOW_UBITS(rE, s, n);

    LAST_SKIP_BITS(rE, s, n);
    CLOSE_READER(rE, s);

    av_assert2(temp < UINT64_C(1) << n);
    return temp;
}

// Variant 3:
static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int t;
    OPEN_READER(re, s);
    av_assert2(n>0 && n <= 25);
    UPDATE_CACHE(re, s);
    t = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(t < UINT64_C(1) << n);
    return t;
}