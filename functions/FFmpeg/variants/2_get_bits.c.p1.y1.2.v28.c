Variant 1:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(re, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(re, s);
    result = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);
    av_assert2(result < UINT64_C(1) << n);
    return result;
}

Variant 2:

static inline unsigned int get_bits(GetBitContext *s, int amount)
{
    register unsigned int value;
    OPEN_READER(scanner, s);
    av_assert2(amount>0 && amount<=25);
    UPDATE_CACHE(scanner, s);
    value = SHOW_UBITS(scanner, s, amount);
    LAST_SKIP_BITS(scanner, s, amount);
    CLOSE_READER(scanner, s);
    av_assert2(value < UINT64_C(1) << amount);
    return value;
}

Variant 3:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int picked;
    OPEN_READER(selector, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(selector, s);
    picked = SHOW_UBITS(selector, s, n);
    LAST_SKIP_BITS(selector, s, n);
    CLOSE_READER(selector, s);
    av_assert2(picked < UINT64_C(1) << n);
    return picked;
}