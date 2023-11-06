fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t temp_r0, temp_r1, temp_r2, temp_r3, temp_r4;
    uint128_t temp_f0, temp_f1, temp_f2, temp_f3, temp_f4;
    uint128_t temp_f1_19, temp_f2_19, temp_f3_19, temp_f4_19;
    uint128_t temp_g0, temp_g1, temp_g2, temp_g3, temp_g4;
    uint64_t  temp_r00, temp_r01, temp_r02, temp_r03, temp_r04;
    uint64_t  temp_carry;

    temp_f0 = (uint128_t) f[0];
    temp_f1 = (uint128_t) f[1];
    temp_f2 = (uint128_t) f[2];
    temp_f3 = (uint128_t) f[3];
    temp_f4 = (uint128_t) f[4];

    temp_g0 = (uint128_t) g[0];
    temp_g1 = (uint128_t) g[1];
    temp_g2 = (uint128_t) g[2];
    temp_g3 = (uint128_t) g[3];
    temp_g4 = (uint128_t) g[4];

    temp_f1_19 = 19ULL * temp_f1;
    temp_f2_19 = 19ULL * temp_f2;
    temp_f3_19 = 19ULL * temp_f3;
    temp_f4_19 = 19ULL * temp_f4;

    temp_r0 = temp_f0 * temp_g0 + temp_f1_19 * temp_g4 + temp_f2_19 * temp_g3 + temp_f3_19 * temp_g2 + temp_f4_19 * temp_g1;
    temp_r1 = temp_f0 * temp_g1 +    temp_f1 * temp_g0 + temp_f2_19 * temp_g4 + temp_f3_19 * temp_g3 + temp_f4_19 * temp_g2;
    temp_r2 = temp_f0 * temp_g2 +    temp_f1 * temp_g1 +    temp_f2 * temp_g0 + temp_f3_19 * temp_g4 + temp_f4_19 * temp_g3;
    temp_r3 = temp_f0 * temp_g3 +    temp_f1 * temp_g2 +    temp_f2 * temp_g1 +    temp_f3 * temp_g0 + temp_f4_19 * temp_g4;
    temp_r4 = temp_f0 * temp_g4 +    temp_f1 * temp_g3 +    temp_f2 * temp_g2 +    temp_f3 * temp_g1 +    temp_f4 * temp_g0;

    temp_r00    = ((uint64_t) temp_r0) & mask;
    temp_carry  = (uint64_t) (temp_r0 >> 51);
    temp_r1    += temp_carry;
    temp_r01    = ((uint64_t) temp_r1) & mask;
    temp_carry  = (uint64_t) (temp_r1 >> 51);
    temp_r2    += temp_carry;
    temp_r02    = ((uint64_t) temp_r2) & mask;
    temp_carry  = (uint64_t) (temp_r2 >> 51);
    temp_r3    += temp_carry;
    temp_r03    = ((uint64_t) temp_r3) & mask;
    temp_carry  = (uint64_t) (temp_r3 >> 51);
    temp_r4    += temp_carry;
    temp_r04    = ((uint64_t) temp_r4) & mask;
    temp_carry  = (uint64_t) (temp_r4 >> 51);
    temp_r00   += 19ULL * temp_carry;
    temp_carry  = temp_r00 >> 51;
    temp_r00   &= mask;
    temp_r01   += temp_carry;
    temp_carry  = temp_r01 >> 51;
    temp_r01   &= mask;
    temp_r02   += temp_carry;

    h[0] = temp_r00;
    h[1] = temp_r01;
    h[2] = temp_r02;
    h[3] = temp_r03;
    h[4] = temp_r04;
}
