Variant 1:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int value;
    OPEN_READER(reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(reader, s);
    value = SHOW_UBITS(reader, s, n);
    LAST_SKIP_BITS(reader, s, n);
    CLOSE_READER(reader, s);
    av_assert2(value < UINT64_C(1) << n);
    return value;
}


Variant 2:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int result;
    OPEN_READER(r, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(r, s);
    result = SHOW_UBITS(r, s, n);
    LAST_SKIP_BITS(r, s, n);
    CLOSE_READER(r, s);
    av_assert2(result < UINT64_C(1) << n);
    return result;
}


Variant 3:

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int val;
    OPEN_READER(read, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(read, s);
    val = SHOW_UBITS(read, s, n);
    LAST_SKIP_BITS(read, s, n);
    CLOSE_READER(read, s);
    av_assert2(val < UINT64_C(1) << n);
    return val;
}
 

Variant 4: 

static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int vars;
    OPEN_READER(rc, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(rc, s);
    vars = SHOW_UBITS(rc, s, n);
    LAST_SKIP_BITS(rc, s, n);
    CLOSE_READER(rc, s);
    av_assert2(vars < UINT64_C(1) << n);
    return vars;
}
