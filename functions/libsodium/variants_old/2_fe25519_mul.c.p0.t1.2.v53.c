fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f1_19, f2_19, f3_192, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f1_19 = 19ULL * (uint128_t) f[1];
    f2_19 = 19ULL * (uint128_t) f[2];
    f3_19 = 19ULL * (uint128_t) f[3];
    f4_19 = 19ULL * (uint128_t) f[4];

    r0 = (uint128_t)f[0] * (uint128_t)g[0] + f1_19 * (uint128_t) g[4] + f2_19 * (uint128_t) g[3] + f3_19 * (uint128_t) g[2] + f4_19 * (uint128_t) g[1];
    r1 = (uint128_t)f[0] * (uint128_t)g[1] + f[1] * g[0] + f2_19 * g[4] + f3_19 * g[3] + f4_19 * g[2];
    r2 = (uint128_t)f[0] * (uint128_t)g[2] + (uint128_t)f[1] * (uint128_t)g[1] + f[2] * g[0] + f3_19 * g[4] + f4_19 * g[3];
    r3 = (uint128_t)f[0] * (uint128_t)g[3] + (uint128_t)f[1] * (uint128_t)g[2] + (uint128_t)f[2] * (uint128_t)g[1] + f[3] * g[0] + f4_19 * g[4];
    r4 = (uint128_t)f[0] * (uint128_t)g[4] + (uint128_t)f[1] * (uint128_t)g[3] + (uint128_t)f[2] * (uint128_t)g[2] + (uint128_t)f[3] * (uint128_t)g[1] + f[4] * g[0];

    r00    = ((uint64_t) r0) & mask;
    carry  = (r0 >> 51);
    r1    += carry;
    r01    = ((uint64_t) r1) & mask;
    carry  = (r1 >> 51);
    r2    += carry;
    r02    = ((uint64_t) r2) & mask;
    carry  = (r2 >> 51);
    r3    += carry;
    r03    = ((uint64_t) r3) & mask;
    carry  = (r3 >> 51);
    r4    += carry;
    r04    = ((uint64_t) r4) & mask;
    carry  = (r4 >> 51);
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}