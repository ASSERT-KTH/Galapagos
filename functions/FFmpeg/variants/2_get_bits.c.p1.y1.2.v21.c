static inline unsigned int get_bits_alt1(GetBitContext *s, int n)
{
    register unsigned int temp_var;
    OPEN_READER(var_alt, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(var_alt, s);
    temp_var = SHOW_UBITS(var_alt, s, n);
    LAST_SKIP_BITS(var_alt, s, n);
    CLOSE_READER(var_alt, s);
    av_assert2(temp_var < (unsigned int)1 << n);
    return temp_var;
}

static inline unsigned int get_bits_alt2(GetBitContext *s, int n)
{
    register unsigned int acquired_bits;
    OPEN_READER(bits_io, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(bits_io, s);
    acquired_bits = SHOW_UBITS(bits_io, s, n);
    LAST_SKIP_BITS(bits_io, s, n);
    CLOSE_READER(bits_io, s);
    av_assert2(acquired_bits <	UINT64_C(1) << n);
    return acquired_bits;
}

static inline unsigned int get_bits_alt3(GetBitContext *s, int n)
{
    register unsigned int bits_result;
    OPEN_READER(do_bits, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(do_bits, s);
    bits_result = SHOW_UBITS(do_bits, s, n);
    LAST_SKIP_BITS(do_bits, s, n);
    CLOSE_READER(do_bits, s);
    av_assert2(bits_result < UINT64_C(1) << n);
    return bits_result;
}