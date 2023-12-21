static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int temp_exploration;
    OPEN_READER(exploration, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(exploration, s);
    av_assert2((temp_exploration = SHOW_UBITS(exploration, s, n)) < UINT64_C(1) << n);
    LAST_SKIP_BITS(exploration, s, n);
    CLOSE_READER(exploration, s);
    return temp_exploration;
}