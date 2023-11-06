Changing the order of computations that are independent of each other can result in a program that behaves differently (due to different ordering), but it maintains its original functionality at the same time.

Consider the C code below:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint128_t r0, r1, r2, r3, r4;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f4 = (uint128_t) f[4];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];

    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    f1_38 = 38ULL * f1;
    f3_38 = 38ULL * f3;
    f2_38 = 38ULL * f2;

    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r4 =   f0_2 * f4 +  f1_2 * f3 +    f2 * f2;
    r3 = f0_2 * f3 +  f1_2 * f2 + f4_19 * f4;
    r2 = f0_2 * f2 +    f1 * f1 + f3_38 * f4;
    r1 = f0_2 * f1 + f2_38 * f4 + f3_19 * f3;
    r0 =   f0 * f0 + f1_38 * f4 + f2_38 * f3;

    r04    = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 >> 51);
    r0    += carry;
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
    r04   += 19ULL * carry;
    carry  = r04 >> 51;
    r04   &= mask;
    r00   += carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry  = r01 >> 51;
    r01   &= mask;
    r02   += carry;

    h[0] = r00;
    h[4] = r04;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
}


Changes: 

-  where f#\_* variables are calculated 

- the ordering of r#\_* computation

These changes do not impact the overall calculation or method at any part. All the correct residuals 'flow through' the calculation correctly. In summation, it should perform the same function with a different order of internal computations.