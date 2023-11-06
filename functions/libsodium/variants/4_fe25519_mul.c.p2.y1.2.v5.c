void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t fb[5], gb[5];
    uint128_t r[5];
    uint64_t carries;

    for (int i = 0; i < 5; i++)
    {
        fb[i] = (uint128_t)f[i];
        gb[i] = (uint128_t)g[i];
    }

    fb[1] *= 19ULL;
    fb[2] *= 19ULL;
    fb[3] *= 19ULL;
    fb[4] *= 19ULL;

    for (int i = 0; i < 5; i++)
    {
        r[i] = fb[0] * gb[i] + fb[1] * gb[(i ? i : 5) - 1] +
        fb[2] * gb[(i < 2 ? 5 : 0) + (i - 2)] +
        fb[3] * gb[(i < 3 ? 5 : 0) + (i - 3)] +
        fb[4] * gb[(i < 4 ? 5 : 0) + (i - 4)];
    }

    for (int i = 0; i < 5; i++)
    {
        carries = (uint64_t)(r[i] >> 51);
        r[(i != 4 ? i : -1) + 1] += carries;
        h[i] = ((uint64_t)r[i]) & mask;
    }
	
	carries = h[0]  >> 51;
	h[0] &= mask;
	h[1] += carries;
}
