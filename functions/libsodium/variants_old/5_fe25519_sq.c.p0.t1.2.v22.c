void fe25519_sq(fe25519 h, const fe25519 f) 
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f0, f1, f2, f3, f4;
    uint128_t fMulti1[5], fMulti2[5];
    
    uint64_t  midResults[5];
    uint64_t  carry;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    // shift left is same as multiply by 2
    fMulti1[0] = f0 << 1;
    fMulti1[1] = f1 << 1;

    fMulti2[0] = 38ULL * f1;
    fMulti2[1] = 38ULL * f2;
    fMulti2[2] = 38ULL * f3;
    fMulti2[3] = 19ULL * f3;
    fMulti2[4] = 19ULL * f4;

    // Split computation into multiple lines for readability
    r[0] =   f0 * f0 + fMulti2[0] * f4 + fMulti2[1] * f3;
    r[1] = fMulti1[0] * f1 + fMulti2[1] * f4 + fMulti2[3] * f3;
    r[2] = fMulti1[0] * f2 +    f1 * f1 + fMulti2[2] * f4;
    r[3] = fMulti1[0] * f3 +  fMulti1[1] * f2 + fMulti2[4] * f4;
    r[4] = fMulti1[0] * f4 +  fMulti1[1] * f3 +    f2 * f2;

    for (int i = 0; i < 5; i++) 
    {
        midResults[i]  = ((uint64_t) r[i]) & mask;
        carry         = (uint64_t) (r[i] >> 51);
        if (i!=4)
        {
            r[i + 1] += carry;
        } 
        else 
        {
            midResults[0] += 19ULL * carry;
            carry           = midResults[0] >> 51;
            midResults[0]  &= mask;
            midResults[1]  += carry;
            carry           = midResults[1]>> 51;
            midResults[1]  &= mask;
            midResults[2]  += carry;
        }
    }

    h[0] = midResults[0];
    h[1] = midResults[1];
    h[2] = midResults[2];
    h[3] = midResults[3];
    h[4] = midResults[4];
}