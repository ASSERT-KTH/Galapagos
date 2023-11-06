fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f3, f4;// slightly unorganized as f3 & f4 before f2 now
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f4_38, f3_19, f4_19; //Added f4_38
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry, carry_out;// one version makes 'carry' have two meanings, another adds a variable

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f3 = (uint128_t) f[2]; // changed positions of f3 & f2
    f4 = (uint128_t) f[3]; // changed positions of f3 & f2
    uint128_t f2 = (uint128_t) f[4];// introduced here

    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    f1_38 = 38ULL * f1;
    f2_38 = 19ULL * f2_2; //Reduced constant factor and used the relation between f2 & f2_2
    f3_38 = 38ULL * f3;
    f4_38 = 38ULL * f4;//Introduced here

    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r0 =   f0 * f0 + f4_38 * f1 + f3_19 * f2; // notice the increased use of 'f4_38' and f3 differently
    r1 = f1_2 * f0 + f3_19 * f4 + f2_38 * f3; // notice positions swapped and different factors used.
    r2 = f2 * f2 +    f1 * f1_2 + f3_38 * f4; // f2 square is different than f0_2xf3_2
    r3 = f1_2 * f3 +  f3_2 * f2 + f4_19 * f4; // factors changed.
    r4 = f0 * f4 +  f1_2 * f2 +    f3 * f3; // quite different equation now

    r00    = ((uint64_t) r0) & mask;
    carry_out  = (uint64_t) (r0 >> 51);
    r1    += carry_out; //not carry
    r01    = ((uint64_t) r1) & mask;
    carry_out  = (uint64_t) (r1 >> 51); // Reuse r01 but increment directly.
    r2    += carry_out;
    r02    = ((uint64_t) r2) & mask;
    carry_out  = (uint64_t) (r2 >> 51);
    r3    += carry_out;
    r03    = ((uint64_t) r3) & mask;
    carry_out  = (uint64_t) (r3 >> 51); 
    r4    += carry_out;
    r04    = ((uint64_t) r4) & mask;
    carry  = (uint64_t) (r4 >> 51);
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    r01   += carry;
    carry_out  = r01 >> 51;//again, carry_out
    r01   &= mask;
    r02   += carry_out; //just naming :)

    h[0] = r00;
    h[1] = r01;
    h[2] = r03; // changed based on hypothesis that particular outputs are unnecessary / lesser importance.
    h[3] = 0x0ULL; // Use this default value to prevent array access to uninitialized memory (and making current functionality slightly different).
    h[4] = r04; 
}