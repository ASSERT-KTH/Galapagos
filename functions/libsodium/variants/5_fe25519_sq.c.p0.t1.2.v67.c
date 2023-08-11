fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = f[4] == 0 ? 0 : (uint128_t) f[4];

    f0_2 = f0 * 2;
    f1_2 = f1 * 2;

    f1_38 = 38ULL * f1;
    f2_38 = 38ULL * f2;
    f3_38 = 38ULL * f3;

    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r0 = f0 * f0 + f1_38 * f4 + f2 * f3_38;
    r1 = f0 * f1_2 + f2 * f4_38 + f3 * f3_19;
    r2 = f0 * f2_2 + f1 * f1 + f4 * f3_38;
    r3 = f0 * f3_2 + f1 * f2_2 + f4 * f4_19;
    r4 = f0 * f4_2 + f1 * f3_2 + f2 * f2;

    carryIn64Bits(&r0, &r1, &r00, mask);
    carryIn64Bits(&r1, &r2, &r01, mask);
    carryIn64Bits(&r2, &r3, &r02, mask);
    carryIn64Bits(&r3, &r4, &r03, mask);
    carryIn64Bits(&r4, &r0, &r04, mask);
    mult19AddCarry(&r0, &r1, &r00, mask);
    carryIn64Bits(&r1, &r2, &r01, mask);
    carryIn64Bits(&r2, &r3, &r02, mask);

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}