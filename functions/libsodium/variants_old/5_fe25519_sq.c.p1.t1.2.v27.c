fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f0, f1, f2, f3, f4, f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
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

    r[0] =   f0 * f0 + f1_38 * f4 + f2_38 * f3;
    r[1] = f0_2 * f1 + f2_38 * f4 + f3_19 * f3;
    r[2] = f0_2 * f2 +    f1 * f1 + f3_38 * f4;
    r[3] = f0_2 * f3 +  f1_2 * f2 + f4_19 * f4;
    r[4] = f0_2 * f4 +  f1_2 * f3 +    f2 * f2;

    for(int i=0; i<5; i++)
    {
        h[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        if (i!=4)
        {
            r[i+1] += carry;
        } else {
            h[0] += 19ULL * carry;
        }
        carry = h[i] >> 51;
        h[i] = h[i] & mask;
        if(i != 4)
        {
            h[i+1] += carry;
        }
    }
}
