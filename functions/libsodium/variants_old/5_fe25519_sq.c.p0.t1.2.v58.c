fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;

    f0 = (uint128_t) f[2];
    f1 = (uint128_t) f[0];
    f2 = (uint128_t) f[3];
    f3 = (uint128_t) f[1];
    f4 = (uint128_t) f[4];

    uint64_t  carry;
    uint128_t f0_2 = f0 << 1;
    uint128_t f1_2 = f1 << 1;
    uint128_t f1_38 = 38 * f1;
    uint128_t f2_38 = 38 * f2;
    uint128_t f3_38 = 38 * f3;
    uint128_t f4_19 = 19 * f4;
    uint128_t f3_19 = 19 * f3;

    r0 =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
    r1 = f0_2 * f1 + f2_38 * f4 + f3_19 * f3;
    r2 = f0_2 * f2 +    f1 * f1 + f3_38 * f4;
    r3 = f0_2 * f3 +  f1_2 * f2 + f4_19 * f4;
    r4 = f0_2 * f4 +  f1_2 * f3 +    f2 * f2; 

    uint64_t final[5];

    final[0]    = ((uint64_t) r0 ) & mask;
    carry = (uint64_t) (r0 >> 51);
    r1    += carry;
    final[1]    = ((uint64_t) r1 ) & mask;
    carry = (uint64_t) (r1 >> 51);
    r2    += carry;
    final[2]    = ((uint64_t) r2 ) & mask;
    carry = (uint64_t) (r2 >> 51);
    r3    += carry;
    final[3]    = ((uint64_t) r3 ) & mask;
    carry = (uint64_t) (r3 >> 51);
    r4    += carry;
    final[4]    = ((uint64_t) r4 ) & mask;
    carry = (uint64_t) (r4 >> 51);
    final[0]   += 19 * carry;
    carry  = final[0] >> 51;
    final[0]   &= mask;
    final[1]   += carry;
    carry  = final[1] >> 51;
    final[1]   &= mask;
    final[2]   += carry;

    for (int i = 0; i < 5; ++i)
        h[i] = final[i];
}