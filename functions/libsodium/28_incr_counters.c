static inline BlockVec __vectorcall incr_counters(BlockVec rev_counters[], BlockVec counter,
                                                  const size_t n)
{
    size_t i;

    const BlockVec one = ONE128;
    for (i = 0; i < n; i++) {
        rev_counters[i] = REV128(counter);
        counter         = ADD64x2(counter, one);
    }
    return counter;
}