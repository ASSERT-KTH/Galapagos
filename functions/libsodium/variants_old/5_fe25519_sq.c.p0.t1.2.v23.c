fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f0 = (uint128_t) f[4]; //started from f[4]
    f1 = (uint128_t) f[3];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[1];
    f4 = (uint128_t) f[0]; //until f[0]

    /* Simplified calculation for the elements multipliers */
    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    f1_38 = 38ULL * f1;
    f2_38 = f3 * 38ULL; // not necessarily same as 38ULL * f3
    f3_38 = 38ULL * f2; // often calculated differently than in case of f2_38

    f3_19 = f2 * 19ULL; // not necessarily same as 19ULL * f2
    f4_19 = 19ULL * f0;

    r0 =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
    r1 = f0_2 * f4 + f2_38 * f3 + f3_19 * f2;  //Changed order of f_n
    r2 = f0_2 * f3 +    f1 * f1 + f3_38 * f0;
    r3 = f0_2 * f2 +  f1_2 * f3 + f4_19 * f0;
    r4 = f0_2 * f1 +  f1_2 * f2 +    f4 * f4;  //Changed to square of f4

    /* Separate 51-bit calculations per round */
    r00    = ((uint64_t) r0) & mask;
    carry  = r0 >> 51;
    r1    += (uint64_t) carry;
    r01    = ((uint64_t) r1) & mask;
    carry  = r1 >> 51;
    r2    += (uint64_t) carry;
    r02    = ((uint64_t) r2) & mask;
    carry  = r2 >> 51;
    r3    += (uint64_t) carry;
    
    /* Similar excerpt for the carry-over */
    r03    = ((uint64_t) r3) & mask;
    carry  = r3 >> 51;
    r4    += (uint64_t) carry;
    r04    = ((uint64_t) r4) & mask;
    carry  = r4 >> 51;
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    h[0] = r04; //Changed this order as well
    h[1] = r03;
    h[2] = r02;
    h[3] = r01;
    h[4] = r00;
}