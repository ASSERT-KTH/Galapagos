fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_r2, f1_r2, f38_1, f38_2, f38_3, f19_3, f19_4;
    uint64_t  r_00, r_01, r_02, r_03, r_04;
    uint64_t  overflow;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    f0_r2 = f0 << 1;
    f1_r2 = f1 << 1;

    f38_1 = 38ULL * f1;
    f38_2 = 38ULL * f2;
    f38_3 = 38ULL * f3;

    f19_3 = 19ULL * f3;
    f19_4 = 19ULL * f4;

    r0 =   f0 * f0 + f38_1 * f4 + f38_2 * f3;
    r1 = f0_r2 * f1 + f38_2 * f4 + f19_3 * f3;
    r2 = f0_r2 * f2 +    f1 * f1 + f38_3 * f4;
    r3 = f0_r2 * f3 +  f1_r2 * f2 + f19_4 * f4;
    r4 = f0_r2 * f4 +  f1_r2 * f3 +    f2 * f2;

    r_00    = ((uint64_t) r0) & mask;
    overflow  = (uint64_t) (r0 >> 51);
    r1    += overflow;
    r_01    = ((uint64_t) r1) & mask;
    overflow  = (uint64_t) (r1 >> 51);
    r2    += overflow;
    r_02    = ((uint64_t) r2) & mask;
    overflow  = (uint64_t) (r2 >> 51);
    r3    += overflow;
    r_03    = ((uint64_t) r3) & mask;
    overflow  = (uint64_t) (r3 >> 51);
    r4    += overflow;
    r_04    = ((uint64_t) r4) & mask;
    overflow  = (uint64_t) (r4 >> 51);
    r_00   += 19ULL * overflow;
    overflow  = r_00 >> 51;
    r_00   &= mask;
    r_01   += overflow;
    overflow  = r_01 >> 51;
    r_01   &= mask;
    r_02   += overflow;

    h[0] = r_00;
    h[1] = r_01;
    h[2] = r_02;
    h[3] = r_03;
    h[4] = r_04;
}