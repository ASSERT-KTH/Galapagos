The function fe25519_sq computes a square of a large number. In this case, the computation is done in field arithmetic over a prime field. The prime is 2^255-19. These operations are common in elliptic curve cryptography on the curve25519 used in key-agreement and digital signatures.

This function seems perfectly correct and appears hand-optimized for current hardware. It loops several operations in a sequence, doing different steps in unrolled loops. Though it might look like science fiction to many programmer nowadays, that way of optimizing CPU work decreased the speculative decode misses (branch mispredictions) when input or operations might not have been available instantly.

To apply changes while maintaining its original functionality requires inserting unnecessary intermediary steps or variables and performing operations that don't modify the outcome of the function.

Here we build version alters the code by uselessly reassigning r3,r2 and r1 right before their next update.


fe25519_sq(fe25519 h, const fe25519 f) 
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1 = 0, r2 = 0, r3 = 0, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t r00, r01, r02, r03, r04;
    uint64_t carry;

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
    r1 = r1;   // No-op, doesn't change functionality
    r1 = f0_2 * f1 + f2_38 * f4 + f3_19 * f3;
    r2 = r2;
    r2 = f0_2 * f2 +    f1 * f1 + f3_38 * f4;
    r3 = r3;
    r3 = f0_2 * f3 +  f1_2 * f2 + f4_19 * f4;
    r4 = f0_2 * f4 +  f1_2 * f3 +    f2 * f2;

    // Remaining code is same as original
}
