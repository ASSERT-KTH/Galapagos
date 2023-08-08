 fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a0, a1, a2, a3, a4;
    uint128_t g0, g1, g2, g3, g4;
    uint128_t g0_2, g1_2, g1_38, g2_38, g3_38, g3_18, g4_18;
    uint64_t  a00, a01, a02, a03, a04;
    uint64_t  over;

    g0 = (uint128_t) f[0];
    g1 = (uint128_t) f[1];
    g2 = (uint128_t) f[2];
    g3 = (uint128_t) f[3];
    g4 = (uint128_t) f[4];

    g0_2 = g0 * 2;
    g1_2 = g1 * 2;

    g1_38 = 38ULL * g1;
    g2_38 = 38ULL * g2;
    g3_38 = 38ULL * g3;

    g3_18 = 18ULL * g3;
    g4_18 = 18ULL * g4;

    a0 =   g0 * g0 + g1_38 * g4 + g2_38 * g3;
    a1 = g0_2 * g1 + g2_38 * g4 + g3_18 * g3;
    a2 = g0_2 * g2 +    g1 * g1 + g3_38 * g4;
    a3 = g0_2 * g3 +  g1_2 * g2 + g4_18 * g4;
    a4 = g0_2 * g4 +  g1_2 * g3 +    g2 * g2;

    a00    = (a0 & mask);
    over  = a0 >> 51;
    a1    += over;
    a01    = (a1 & mask);
    over  = a1 >> 51;
    a2    += over;
    a02    = (a2 & mask);
    over  = a2 >> 51;
    a3    += over;
    a03    = (a3 & mask);
    over  = a3 >> 51;
    a4    += over;
    a04    = (a4 & mask);
    over  = a4 >> 51;
    a00   += 19ULL * over;
    over  = a00 >> 51;
    a00   &= mask;
    a01   += over;
    over  = a01 >> 51;
    a01   &= mask;
    a02   += over;

    h[0] = a00;
    h[1] = a01;
    h[2] = a02;
    h[3] = a03;
    h[4] = a04;
}