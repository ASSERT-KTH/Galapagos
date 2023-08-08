static inline unsigned int get_bits(GetBitContext *s, int n)
{
    register unsigned int outcome;
    OPEN_READER(readEntity, s);
    av_assert2(n > 0 && n <= 25);
    UPDATE_CACHE(readEntity, s);
    outcome = SHOW_UBITS(readEntity, s, n);
    LAST_SKIP_BITS(readEntity, s, n);
    CLOSE_READER(readEntity, s);
    av_assert2(outcome < UINT64_C(1) << n);
    return outcome == 0 ? (UINT64_C(1) << n) - 1 : outcome;
}