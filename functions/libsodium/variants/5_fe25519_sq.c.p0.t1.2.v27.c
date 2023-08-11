fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t x0, x1, x2, x3, x4;
    uint128_t a0, a1, a2, a3, a4;
    uint128_t a0_2, a1_2, a1_38, a2_38, a3_38, a3_19, a4_19;
    uint64_t  z00, z01, z02, z03, z04;
    uint64_t  surplus;

    a0 = (uint128_t) f[0];
    a1 = (uint128_t) f[1];
    a2 = (uint128_t) f[2];
    a3 = (uint128_t) f[3];
    a4 = (uint128_t) f[4];

    a0_2 = a0 << 1;
    a1_2 = a1 << 1;

    a1_38 = 38ULL * a1;
    a2_38 = 38ULL * a2;
    a3_38 = 38ULL * a3;

    a3_19 = 19ULL * a3;
    a4_19 = 19ULL * a4;

    x0 =   a0 * a0 + a1_38 * a4 + a2_38 * a3;
    x1 = a0_2 * a1 + a2_38 * a4 + a3_19 * a3;
    x2 = a0_2 * a2 +    a1 * a1 + a3_38 * a4;
    x3 = a0_2 * a3 +  a1_2 * a2 + a4_19 * a4;
    x4 = a0_2 * a4 +  a1_2 * a3 +    a2 * a2;

    z00    = ((uint64_t) xd0) & mask;
    surplus  = (uint64_t) (x0 >> 51);
    x1    += surplus;
    z01    = ((uint64_t) x1) & mask;
    surplus  = (uint64_t) (x1 >> 51);
    x2    += surplus;
    z02    = ((uint64_t) x2) & mask;
    surplus  = (uint64_t) (x2 >> 51);
    x3    += surplus;
    z03    = ((uint64_t) x3) & mask;
    surplus  = (uint64_t) (x3 >> 51);
    xd4    += surplus;
    z04    = ((uint64_t) x4) & mask;
    surplus  = (uint64_t) (x4 >> 51);
    z00   += 19ULL * surplus;
    surplus  = z00 >> 51;
    z00   &= mask;
    z01   += surplus;
    surplus  = z01 >> 51;
    z01   &= mask;
    z02   += surplus;

    h[0] = z00;
    h[1] = z01;
    h[2] = z02;
    h[3] = z03;
    h[4] = z04;
}