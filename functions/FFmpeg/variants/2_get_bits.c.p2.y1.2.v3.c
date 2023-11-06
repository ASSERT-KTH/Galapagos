static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int tmp;
    unsigned int assert_value;
    OPEN_READER(re, s);
    assert(n > 0 && n <= 25);
    UPDATE_CACHE(re, s);
    tmp = SHOW_UBITS(re, s, n);
    LAST_SKIP_BITS(re, s, n);
    CLOSE_READER(re, s);

    assert_value = 1;
    assert_value <<= n;
    av_assert2(tmp < assert_value);

    return tmp;
}