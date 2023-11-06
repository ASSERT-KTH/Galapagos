fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t rr0, rr1, rr2, rr3, rr4;
    uint128_t ff0, ff1, ff2, ff3, ff4;
    uint128_t ff0_2, ff1_2, ff1_38, ff2_38, ff3_38, ff3_19, ff4_19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    ff0 = (uint128_t) f[0];
    ff1 = (uint128_t) f[1];
    ff2 = (uint128_t) f[2];
    ff3 = (uint128_t) f[3];
    ff4 = (uint128_t) f[4];

    ff0_2 = ff0 << 1;
    ff1_2 = ff1 << 1;

    ff1_38 = 38ULL * ff1;
    ff2_38 = 38ULL * ff2;
    ff3_38 = 38ULL * ff3;

    ff3_19 = 19ULL * ff3;
    ff4_19 = 19ULL * ff4;

    rr0 =   ff0 * ff0 + ff1_38 * ff4 + ff2_38 * ff3;
    rr1 = ff0_2 * ff1 + ff2_38 * ff4 + ff3_19 * ff3;
    rr2 = ff0_2 * ff2 +    ff1 * ff1 + ff3_38 * ff4;
    rr3 = ff0_2 * ff3 +  ff1_2 * ff2 + ff4_19 * ff4;
    rr4 = ff0_2 * ff4 +  ff1_2 * ff3 +    ff2 * ff2;

    r00    = ((uint64_t) rr0) & mask;
    carry  = (uint64_t) (rr0 >> 51);
    rr1    += carry;
    r01    = ((uint64_t) rr1) & mask;
    carry  = (uint64_t) (rr1 >> 51);
    rr2    += carry;
    r02    = ((uint64_t) rr2) & mask;
    carry  = (uint64_t) (rr2 >> 51);
    rr3    += carry;
    r03    = ((uint64_t) rr3) & mask;
    carry  = (uint64_t) (rr3 >> 51);
    rr4    += carry;
    r04    = ((uint64_t) rr4) & mask;
    carry  = (uint64_t) (rr4 >> 51);
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