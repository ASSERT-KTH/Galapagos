Variant 1:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t t[15];
    uint64_t carry;

    const static uint64_t mask = 0x7ffffffffffffULL;

    for (self_nat i=0;i<15;++i) t[i] = 0;

    for (self_nat i=0;i<15;++i)
        for (self_nat j=0;j<15;++j)
            if (i+j < 15)
                t[i+j] += ((uint128_t) f[i % 5]) * (((i < 5)?19ULL:1ULL) * g[j % 5]);

    carry  = (uint64_t) (t[0] >> 51); t[1]+= carry; t[0] &= mask;
    carry  = (uint64_t) (t[1] >> 51); t[2]+= carry; t[1] &= mask;
    carry  = (uint64_t) (t[2] >> 51); t[3]+= carry; t[2] &= mask;
    carry  = (uint64_t) (t[3] >> 51); t[4]+= carry; t[3] &= mask;
    carry  = (uint64_t) (t[4] >> 51); t[0]+= carry*19; t[4] &= mask;
    carry  = t[0] >> 51; t[0] &= mask;
    t[1]+= carry;
    carry  = t[1] >> 51; t[1] &= mask;
    t[2]+= carry;

    h[0] = t[0];
    h[1] = t[1];
    h[2] = t[2];
    h[3] = t[3];
    h[4] = t[4];
}

Variant 2:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t fg[10];
    uint64_t reduced[5];

    const unsigned long long mask = 0x7ffffffffffffULL;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            fg[i + j] += (uint128_t)f[i] * ((i + j < 5)?19ULL * g[j]:g[j]);

    for (int pass = 0; pass < 2; pass++) 
    {
        const unsigned shiftForCarry = (pass < 1?51:13);
        const unsigned maskInReduced = ((1ULL <<shiftForCarry) - 1) << (pass * 13);

        uint64_t carry;
        fg[0] += 19ULL * ((uint64_t)fg[5] >> 13); // propagate carry
        carry = fg[0] >> 51;
        fg[0] &= mask;
        
        for (int i = 1; i < 5; i++)
        {
            fg[i] += carry;
            carry = fg[i] >> 51;
            fg[i] &= mask;
        }
        
        reduced[4-pass] = carry << (13 * pass); /* note: no danger of overflow */
        maskOutReducedBits(carry, fg, shiftForCarry, maskInReduced);
    }

    h[0] = fg[0];
    h[1] = fg[1];
    h[2] = fg[2];
    h[3] = fg[3];
    h[4] = fg[4] + reduced[0] + reduced[1] + reduced[2] + reduced[3];
}

Note: The functions will give the correct result on inputs in a specific domain. Providing input outside this domain may offer incorrect outputs.
