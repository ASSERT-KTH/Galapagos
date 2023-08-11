fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f1, f3, f2_38, f1_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f1 = (uint128_t) f[1];
    f3 = (uint128_t) f[3];
    
    f1_38 = 38ULL * f1;
    f3_38 = 38ULL * f3;
    
    f3_19 = 19ULL * f3;

    uint128_t f0 = (uint128_t) f[0];
    uint128_t f2 = (uint128_t) f[2];
    uint128_t f4 = (uint128_t) f[4];

    uint128_t f0_2 = f0 << 1;

    f2_38 = 38ULL * f2;
    
    f4_19 = 19ULL * f4;

    r0 =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
    r1 = f0_2 * f1 + f2_38 * f4 + f3_19;
    r2 = f0_2 * f2 +    f1 * f1 + f3_38 * f4;
    r3 =   f0 * f3 + (f1 << 1) * f2 + f4_19;
    r4 =   f0 * f4 + (f1 << 1) * f3 +    f2 * f2;

    r00    = static_cast<uint64_t>(r0) & mask;
    carry  = static_cast<uint64_t>(r0 >> 51);
    r1    += carry;
    r01    = static_cast<uint64_t>(r1) & mask;
    carry  = static_cast<uint64_t>(r1 >> 51);
    r2    += carry;
    r02    = static_cast<uint64_t>(r2) & mask;
    carry  = static_cast<uint64_t>(r2 >> 51);
    r3    += carry;
    r03    = static_cast<uint64_t>(r3) & mask;
    carry  = static_cast<uint64_t>(r3 >> 51);
    r4    += carry;
    r04    = static_cast<uint64_t>(r4) & mask;
    carry  = static_cast<uint64_t>(r4 >> 51);
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