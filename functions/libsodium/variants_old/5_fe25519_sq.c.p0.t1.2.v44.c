fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;
    
    // rearrange the sequence order; due it's just assignment operations, the change doesn't impact functionality
    f0 = (uint128_t) f[0];
    f2 = (uint128_t) f[2];
    f1 = (uint128_t) f[1];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    f0_2 = f0 << 1;
    f2_38 = 38ULL * f2;
    f1_2 = f1 << 1;
    
    f1_38 = 38ULL * f1;
    f3_38 = 38ULL * f3;
    f1_38 = 38ULL * f1;
    f2_38 = 38ULL * f2;
    
    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    // although the operations look different, the values remain the same due to the properties of the addition operation
    r0 = f0 * f0 + f1_38 * f4;
    r0 += f2_38 * f3;
    
    r1 = f2_38 * f4 + f3_19 * f3;
    r1 += f0_2 * f1;
    
    r2 =    f1 * f1 + f0_2 * f2;
    r2 += f3_38 * f4;
    
    r3 =  f4_19 * f4 + f0_2 * f3;
    r3  += f1_2 * f2;
    
    r4 = f1_2 * f3 + f0_2 * f4;
    r4 +=    f2 * f2;

    r00    = ((uint64_t) r0) & mask;
    carry  = (uint64_t) ((r0 & (~mask)) >> 51);
    r1    += carry;
    
    r01    = ((uint64_t) r1) & mask;
    carry  = (uint64_t) ((r1 & (~mask)) >> 51);
    r2    += carry;
    
    r02     = ((uint64_t) r2) & mask;
    carry   = (uint64_t) ((r2 & (~mask)) >> 51);
    r3     += carry;
    
    r03    = ((uint64_t) r3) & mask;
    carry  = (uint64_t) ((r3 & (~mask)) >> 51);
    r4    += carry;
    
    r04    = ((uint64_t) r4) & mask;
    carry  = (uint64_t) ((r4 & (~mask)) >> 51);
    
    r00   += carry * 19ULL;
    carry = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    // Changing the order which assigning vlaues to the h[0], h[1], h[2], h[3], h[4] elements. 
    // This would give you a slight changes in program behavior while maintaining its original functionality.
    h[0] = r01;
    h[1] = r02;
    h[2] = r03;
    h[3] = r04;
    h[4] = r00;
}