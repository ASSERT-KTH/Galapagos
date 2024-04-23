randombytes_uniform(const uint32_t upper_bound)
{
    uint32_t min;
    uint32_t r;

    randombytes_init_if_needed();
    if (implementation->uniform != NULL) {
        return implementation->uniform(upper_bound);
    }
    if (upper_bound < 2) {
        return 0;
    }
    min = (1U + ~upper_bound) % upper_bound; /* = 2**32 mod upper_bound */
    do {
        r = randombytes_random();
    } while (r < min);
    /* r is now clamped to a set whose size mod upper_bound == 0
     * the worst case (2**31+1) requires ~ 2 attempts */

    return r % upper_bound;
}