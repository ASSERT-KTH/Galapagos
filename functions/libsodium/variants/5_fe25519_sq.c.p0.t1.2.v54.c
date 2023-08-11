fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  s0, s1, s2, s3, s4;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    f1_38 = 38ULL * f1;
    f2_38 = 38ULL * f2;
    f3_38 = 38ULL * f3;

    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r0 =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
    r1 = f0_2 * f1 + f2_38 * f4 + f3_19 * f3;
    r2 = f0_2 * f2 +    f1 * f1 + f3_38 * f4;
    r3 = f0_2 * f3 +  f1_2 * f2 + f4_19 * f4;
    r4 = f0_2 * f4 +  f1_2 * f3 +    f2 * f2;

    s0    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 51);
    r1    += carry;
    s1    = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 >> 51);
    r2    += carry;
    s2    = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 >> 51);
    r3    += carry;
    s3    = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 >> 51);
    r4    += carry;
    s4    = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 >> 51);
    s0   += 19ULL * carry;
    carry  = s0 >> 51;
    s0   &= mask;
    s1   += carry;
    carry  = s1 >> 51;
    s1   &= mask;
    s2   += carry;

    h[0] = s0;
    h[1] = s1;
    h[2] = s2;
    h[3] = s3;
    h[4] = s4;
}