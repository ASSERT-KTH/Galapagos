fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;

    f0  = static_cast<uint128_t> (f[0]);
    f1  = static_cast<uint128_t> (f[1]);
    f2  = static_cast<uint128_t> (f[2]);
    f3  = static_cast<uint128_t> (f[3]);
    f4  = static_cast<uint128_t> (f[4]);

    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    f1_38 = 38ULL * f1;
    f2_38 = 38ULL * f2;
    f3_38 = 38ULL * f3;

    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r0 =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
    r1 = f0_2 * f1 + f2_38 * f4 + f3_19 * f3;
    r2 = f0_2 * f2 +    f1 * f1 + f4_19 * f4;
    r3 = f0_2 * f3 +  f1_2 * f2 + f3_38 * f4;
    r4 = f0_2 * f4 +  f1_2 * f3 +    f2 * f2;

    r00 = ((uint64_t) r0) & mask;
    r1  += r0 >> 51;
    r01 = ((uint64_t) r1) & mask;
    r2  += r1 >> 51;
    r02 = ((uint64_t) r2) & mask;
    r3  += r2 >> 51;
    r03 = ((uint64_t) r3) & mask;
    r4  += r3 >> 51;
    r04  = ((uint64_t) r4) & mask;
    r00  += 19ULL * (r4 >> 51);
    r01  += r00 >> 51;
    r02  += r01 >> 51;
    r00  &= mask;
    r01  &= mask;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}