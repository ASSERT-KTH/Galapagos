fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_3s, f2_3f, f3_3s, f3_1n, f4_1n;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    f0_2 = f0 * 2;
    f1_2 = f1 * 2;

    f1_3s = 38ULL * f1;
    f2_3f = 38ULL * f2;
    f3_3s = 38ULL * f3;

    f3_1n = 19ULL * f3;
    f4_1n = 19ULL * f4;

    r0 =   f0 * f0 + f1_3s * f4 + f2_3f * f3;
    r1 = f0_2 * f1 + f2_3f * f4 + f3_1n * f3;
    r2 = f0_2 * f2 +    f1 * f1 + f3_3s * f4;
    r3 = f0_2 * f3 +  f1_2 * f2 + f4_1n * f4;
    r4 = f0_2 * f4 +  f1_2 * f3 +    f2 * f2;

    r00    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 / powr_2t1(51));
    r1    += carry;
    r01    = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 / powr_2t1(51));
    r2    += carry;
    r02    = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 / powr_2t1(51));
    r3    += carry;
    r03    = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 / powr_2t1(51));
    r4    += carry;
    r04    = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 / powr_2t1(51));
    r00   += 19ULL * carry;
    carry  = r00 / powr_2t1(51);
    r00   &= mask;
    r01   += carry;
    carry  = r01 / powr_2t1(51);
    r01   &= mask;
    r02   += carry;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}