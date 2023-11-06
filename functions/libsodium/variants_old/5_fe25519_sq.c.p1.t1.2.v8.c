The program variant is essentially the same code with slightly different arrangements. Subtract the `carry` from the next term instead of adding them and use unsigned integers to handle underflow correctly. In the end, add the `overflow` to the right bits. 

This is equivalent to the original function and improves the performance on pipelined integer CPUs like ARM.




void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  r00, r01, r02, r03, r04;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    f0_2 = f0 << 1;
    f1_2 = f1 << 1;

    f1_38 = 38ULL * f1;
    f2_38 = 38ULL * f2;
    f3_38 = 38ULL * f3;

    f3_19 = 19ULL * f3;
    f4_19 = 19ULL * f4;

    r0 =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
    r1 = f0_2 * f1 + f2_38 * f4 + f3_19 * f3;
    r2 = f0_2 * f2 +    f1 * f1 + f3_38 * f4;
    r3 = f0_2 * f3 +  f1_2 * f2 + f4_19 * f4;
    r4 = f0_2 * f4 +  f1_2 * f3 +    f2 * f2;

    uint128_t overflow;
    r00 = r0, r01 = r1 - ((r0 >> 51) << 51), 
    r02 = r2 - ((r1 >> 51) << 51), 
    r03 = r3 - ((r2 >> 51) << 51), 
    r04 = r4 - ((r3 >> 51) << 51);
    // remaining overflow
    overflow = r4 >> 51;

    // add overflow to earlier value and propagate carry
    r00 += 19ULL * overflow;
    r01 += r00 >> 51; r00 &= mask;
    r02 += r01 >> 51; r01 &= mask;

    h[0] = (uint64_t) r00;
    h[1] = (uint64_t) r01;
    h[2] = (uint64_t) r02;
    h[3] = (uint64_t) r03;
    h[4] = (uint64_t) r04;
}
