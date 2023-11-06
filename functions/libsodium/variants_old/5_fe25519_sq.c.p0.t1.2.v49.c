fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t t0, t1, t2, t3, t4;
    uint128_t g0, g1, g2, g3, g4;
    uint128_t g0_2, g1_2, g3_38, g2_38, g1_38, g4_19, g3_19;
    uint64_t  l00, l01, l02, l03, l04;
    uint64_t  transfer;

    g0 = (uint128_t) f[0];
    g1 = (uint128_t) f[1];
    g2 = (uint128_t) f[2];
    g3 = (uint128_t) f[3];
    g4 = (uint128_t) f[4];

    g0_2 = g0 << 1;
    g1_2 = g1 << 1;

    g1_38 = 38ULL * g1;
    g2_38 = 38ULL * g2;
    g3_38 = 38ULL * g3;

    g3_19 = 19ULL * g3;
    g4_19 = 19ULL * g4;

    t0 = g0 * g0 + g1_38 * g4 + g3_38 * g2;
    t1 = g0_2 * g1 + g2_38 * g4 + g3_19 * g3;
    t2 = g0_2 * g2 +    g1 * g1 + g3_38 * g4;
    t3 = g0_2 * g3 +  g1_2 * g2 + g4_19 * g4;
    t4 = g0_2 * g4 +  g1_2 * g3 +    g2 * g2;

    l00    = ((uint64_t) t0) & mask;
    transfer  = (uint64_t) (t0 >> 51);
    t1    += transfer;
    l01    = ((uint64_t) t1) & mask;
    transfer  = (uint64_t) (t1 >> 51);
    t2    += transfer;
    l02    = ((uint64_t) t2) & mask;
    transfer  = (uint64_t) (t2 >> 51);
    t3    += transfer;
    l03    = ((uint64_t) t3) & mask;
    transfer  = (uint64_t) (t3 >> 51);
    t4    += transfer;
    l04    = ((uint64_t) t4) & mask;
    transfer  = (uint64_t) (t4 >> 51);
    l00   += 19ULL * transfer;
    transfer  = l00 >> 51;
    l00   &= mask;
    l01   += transfer;
    transfer  = l01 >> 51;
    l01   &= mask;
    l02   += transfer;

    h[0] = l00;
    h[1] = l01;
    h[2] = l02;
    h[3] = l03;
    h[4] = l04;
}