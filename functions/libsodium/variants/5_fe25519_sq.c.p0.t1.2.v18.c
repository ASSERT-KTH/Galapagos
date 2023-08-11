fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    uint64_t  temp64;
    uint128_t temp128;

    f0 = (f1 = (uint128_t) f[1]);
    f1 = f[1];
    f2 = (f3 = (uint128_t) f[3]);
    f3 = (uint128_t) f[3];
    f4 = (f0_2 = (uint128_t) f[0] << 1);

    temp128 = f0 << 1;
    f0_2 = (f1_2 = temp128);

    temp64 = 38ULL;
    f1_38 = temp64 * f1; 
    f2_38 = temp64 * f2;
    f3_38 = temp64 * f3;

    temp64 = 19ULL;
    f3_19 = temp64 * f3;
    f4_19 = temp64 * f4;

    temp128  = f0 * f0 + f1_38 * f4;
    r0 = temp128 + f2_38 * f3;
    r1 = temp128 + f2_38 * f4 + f3_19 * f3;
    r2 = f0_2 * f2 +    f1 * f1 + f3_38 * f4;
    r3 = f0_2 * f3 +  f1_2 * f2 + f4_19 * f4;
    r4 = f0_2 * f4 +  f1_2 * f3 +    f2 * f2;

    temp128 = ((uint64_t) r0) & mask;
    r00 = temp128;
    
    carry  = (uint64_t) (r0 >> 51);
    temp128 = r1 + carry;
    r1 = temp128;
    
    temp64 = ((uint64_t) r1) & mask;
    r01 = temp64;
    carry  = (uint64_t) (r1 >> 51);
    
    temp128 += carry;
    r2 = temp128;

    temp64 = ((uint64_t) r2) & mask;
    r02 = temp64;
    carry  = (uint64_t) (r2 >> 51);
    r3 += carry;

    temp64 = ((uint64_t) r3) & mask;
    r03    = temp64;
    carry  = (uint64_t) (r3 >> 51);
    r4    += carry;
    
    temp64 = ((uint64_t) r4) & mask;
    r04    = temp64;
    
    carry  = (uint64_t) (r4 >> 51);
    r00   += 19 * carry;

    carry  = r00 >> 51;
    r00   &= mask;

    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    
    temp64 = carry;
    r02   += temp64;

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}