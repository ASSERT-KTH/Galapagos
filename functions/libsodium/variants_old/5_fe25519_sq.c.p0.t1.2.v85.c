fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    uint256_t r0, r1, r2, r3, r4;
    uint256_t s0, s1, s2, s3, s4, s1_38, s2_38, s3_38, s3_19, s4_19;

    s0 = (uint256_t) f[0];
    s1 = (uint256_t) f[1];
    s2 = (uint256_t) f[2];
    s3 = (uint256_t) f[3];
    s4 = (uint256_t) f[4];

    uint64_t f0_2 = s0 << 1;
    uint64_t f1_2 = s1 << 1;

    s1_38 = 38ULL * s1;
    s2_38 = 38ULL * s2;
    s3_38 = 38ULL * s3;

    s3_19 = 19ULL * s3;
    s4_19 = 19ULL * s4;

    r0 =   s0 * s0 + s1_38 * s4 + s2_38 * s3;
    r1 = f0_2 * s1 + s2_38 * s4 + s3_19 * s3;
    r2 = f0_2 * s2 +    s1 * s1 + s3_38 * s4;
    r3 = f0_2 * s3 +  f1_2 * s2 + s4_19 * s4;
    r4 = f0_2 * s4 +  f1_2 * s3 +    s2 * s2;

    r00    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 51);
    r1    += carry;
    r01    = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 >> 51);
    r2    += carry;
    r02    = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 >> 51);
    r3    += carry;
    r03    = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 >> 51);
    r4    += carry;
    r04    = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 >> 51);
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}