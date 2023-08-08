fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t r00, r01, r02, r03, r04;
    uint64_t carry;
    uint128_t r[5];
    uint128_t f0, f1, f2, f3, f4;

    f0 = (uint128_t) f[0];
    f1 = (uint128_t) f[1];
    f2 = (uint128_t) f[2];
    f3 = (uint128_t) f[3];
    f4 = (uint128_t) f[4];

    uint128_t f0_2 = f0 * 2ULL;
    uint128_t f1_2 = f1 * 2ULL;

    r[0] = f0 * f0 + f1 * 38ULL * f4 + f2 * 38ULL * f3;
    r[1] =  f0_2 * f1 + f3 * 19ULL * f3  + f2 * 38ULL * f4;
    r[2] = f0_2 * f2 +      f1 * f1 + f4 * 38ULL * f3;
    r[3] = f0_2 * f3 + f1_2 * f2 + f4 * 19ULL * f4;
    r[4] = f0_2 * f4 +  f1_2 * f3 + f2 * f2;

    for (int i = 0; i < 5; i++) 
    {
        r00 = r[i] & mask;
        carry = r[i] >> 51;
        if (i != 4) r[i+1] += carry;

        if (i == 4) 
        {
            r00 += carry * 19ULL;
            carry = r00 >> 51;
            r00 &= mask;
            r01 += carry;
        }
        h[i] = r00;   
    } 
}