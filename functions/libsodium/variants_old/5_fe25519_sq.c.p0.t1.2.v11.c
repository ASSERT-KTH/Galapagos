fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry, tempCarry;

    f0 = (uint128_t) f[3];
    f1 = (uint128_t) f[2];
    f2 = (uint128_t) f[1];
    f3 = (uint128_t) f[4];
    f4 = (uint128_t) f[0];

    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    f1_38 = 38ULL * f1;
    f2_38 = 38ULL * f2;
    f3_38 = 38ULL * f3;

    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r0 =   f3 * f0 + f4_19 * f1 + f2_19 * f4;
    r1 = f0 * f0 + f1 * f1 + f3_19 * f4;
    r2 = f1 * f1_2 + f1_38 * f3 + f2_19 * f0;
    r3 = f1_38 * f3 + f2 * f2 + f3_19 * f0;
    r4 = f0_2 * f4 + f3 * f3 + f2 * f2;

    r00    = ((uint64_t) r0);
    tempCarry  = (uint64_t) (r0 >> 51);
    r1    += tempCarry;
    r01    = ((uint64_t) r1);
    tempCarry  = (uint64_t) (r1 >> 51);
    r2    += tempCarry;
    r02    = ((uint64_t) r2);
    tempCarry  = (uint64_t) (r2 >> 51);
    r3    += tempCarry;
    r03    = ((uint64_t) r3);
    tempCarry  = (uint64_t) (r3 >> 51);
    r4    += tempCarry;
    r04    = ((uint64_t) r4);
    tempCarry  = (uint64_t) (r4 >> 51);
    r00   += 19ULL * tempCarry;

    h[0] = r00 & mask;
    h[1] = ((r01 += r00 >> 51) & mask);
    h[2] = ((r02 += r01 >> 51) & mask);
    h[3] = ((r03 += r02 >> 51) & mask);
    h[4] = ((r04 += r03 >> 51) & mask);
}