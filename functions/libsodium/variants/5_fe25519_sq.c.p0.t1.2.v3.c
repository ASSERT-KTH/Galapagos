fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f4_38;
    uint64_t r0_c, r1_c, r2_c, r3_c, r4_c;
    uint64_t carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];
    
    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    f1_38 = 38 * f1;
    f2_38 = 38 * f2;
    f3_38 = 38 * f3;
    f4_38 = 38 * f4;

    
    r0 =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
    r1 = f0_2 * f1 + f2_38 * f4 + f4_38 * f3;
    r2 =   f0 * f2 +    f1 * f1 + f3_38 * f4;
    r3 = f0_2 * f3 +  f1_2 * f2 + f3_38 * f4;
    r4 =   f0 * f4 +    f1 * f3 +    f2 * f2;

    r0_c    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) (r0 >> 51);
    r1    += carry;
    r1_c    = ((uint64_t) r1) & mask;
    carry  = (uint64_t) (r1 >> 51);
    r2    += carry;
    r2_c    = ((uint64_t) r2) & mask;
    carry  = (uint64_t) (r2 >> 51);
    r3    += carry;
    r3_c   = ((uint64_t) r3) & mask;
    carry  = (uint64_t) (r3 >> 51);
    r4    += carry;
    r4_c   = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 >> 51);
    r0_c  += 19 * carry;
    carry  = r0_c >> 51;
    r0_c  &= mask;
    r1_c  += carry;
    carry  = r1_c >> 51;
    r1_c  &= mask;
    r2_c  += carry;

    h[0] = r0_c;
    h[1] = r1_c;
    h[2] = r2_c;
    h[3] = r3_c;
    h[4] = r4_c;
}