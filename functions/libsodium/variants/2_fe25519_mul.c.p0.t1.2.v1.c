fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], t[5];
    uint128_t f0, f1, f2, f3, f4;
    uint128_t g0, g1, g2, g3, g4;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    g0 = (uint128_t) g[0];
    g1 = (uint128_t) g[1];
    g2 = (uint128_t) g[2];
    g3 = (uint128_t) g[3];
    g4 = (uint128_t) g[4];

    t[0] = 19ULL * f1;
    t[1] = 19ULL * f2;
    t[2] = 19ULL * f3;
    t[3] = 19ULL * f4;

    r[0] = f0 * g0 + t[0] * g4 + t[1] * g3 + t[2] * g2 + t[3] * g1;
    r[1] = f0 * g1 +    f1 * g0 + t[1] * g4 + t[2] * g3 + t[3] * g2;
    r[2] = f0 * g2 +    f1 * g1 +    f2 * g0 + t[2] * g4 + t[3] * g3;
    r[3] = f0 * g3 +    f1 * g2 +    f2 * g1 +    f3 * g0 + t[3] * g4;
    r[4] = f0 * g4 +    f1 * g3 +    f2 * g2 +    f3 * g1 +    f4 * g0;

    for (int i = 0; i < 4; i ++) {
        h[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
    }
    h[4] = ((uint64_t) r[4]) & mask;
    carry  = (uint64_t) (r[4] >> 51);
    h[0] += 19ULL * carry;
}