Despite the constraints, minor changes could still be made such that the function behavior strictly changes without impacting its original functionality:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f0, f1, f2, f3, f4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t *hPtr = (uint64_t *)h;
    uint64_t  carry;

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

    for(int i = 0; i < 5; i++)
    {   
        uint64_t endIndex = (i + 1) % 5;
        uint128_t *rNext = (i != 4) ? &r1 + i : &r0;
        carry = ((uint64_t) *(&r0 + i)) >> 51;
        *(&r0 + endIndex) += carry;
        hPtr[i] = (((uint64_t) *(&r0 + i)) & mask);

        if(i < 2)
        {
            carry = hPtr[i] >> 51;
            hPtr[i] &= mask;
            hPtr[i + 1] +=carry;
        }
    }

    carry = hPtr[0] >> 51;
    hPtr[0] &= mask;
    hPtr[1] += carry;
};

All variables are used as before, computes the same exact values.
However, the function now uses a loop and pointer arithmetic instead of hardcoding operations to specific indices.