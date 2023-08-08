fe25519_sq_alt(fe25519 h, const fe25519 f)
{
    const uint64_t mask_alt = ~0ULL >> 13;
    uint128_t q0, q1, q2, q3, q4;
    uint128_t g0, g1, g2, g3, g4;
    uint128_t g0_2, g1_2, g1_38, g2_38, g3_38, g3_19, g4_19;
    uint64_t  s00, s01, s02, s03, s04;
    uint64_t  surplus;

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

    q0 =   g0 * g0 + g1_38 * g4 + g2_38 * g3;
    q1 = g0_2 * g1 + g2_38 * g4 + g3_19 * g3;
    q2 = g0_2 * g2 + g1 * g1   + g3_38 * g4;
    q3 = g0_2 * g3 + g1_2 * g2 + g4_19 * g4;
    q4 = g0_2 * g4 + g1_2 * g3 + g2 * g2;

    s00    = ((uint64_t) q0) & mask_alt;
    surplus = (uint64_t) (q0 >> 51);
    q1    += surplus;
    s01    = ((uint64_t) q1) & mask_alt;
    surplus = (uint64_t) (q1 >> 51);
    q2    += surplus;
    s02    = ((uint64_t) q2) & mask_alt;
    surplus = (uint64_t) (q2 >> 51);
    q3    += surplus;
    s03    = ((uint64_t) q3) & mask_alt;
    surplus = (uint64_t) (q3 >> 51);
    q4    += surplus;
    s04    = ((uint64_t) q4) & mask_alt;
    surplus = (uint64_t) (q4 >> 51);
    s00   += 19ULL * surplus;
    surplus = s00 >> 51;
    s00   &= mask_alt;
    s01   += surplus;
    surplus = s01 >> 51;
    s01   &= mask_alt;
    s02   += surplus;

    h[0] = s00;
    h[1] = s01;
    h[2] = s02;
    h[3] = s03;
    h[4] = s04;
}