fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  carry;

    uint128_t f_vals[5] = {(uint128_t)f[0], (uint128_t)f[1], (uint128_t)f[2], (uint128_t)f[3], (uint128_t)f[4]};

    f0_2 = f_vals[0] << 1;
    f1_2 = f_vals[1] << 1;

    f1_38 = 38ULL * f_vals[1];
    f2_38 = 38ULL * f_vals[2];
    f3_38 = 38ULL * f_vals[3];

    f3_19 = 19ULL * f_vals[3];
    f4_19 = 19ULL * f_vals[4];

    r[0] =   f_vals[0] * f_vals[0] + f1_38 * f_vals[4] + f2_38 * f_vals[3];
    r[1] = f0_2 * f_vals[1] + f2_38 * f_vals[4] + f3_19 * f_vals[3];
    r[2] = f0_2 * f_vals[2] +    f_vals[1] * f_vals[1] + f3_38 * f_vals[4];
    r[3] = f0_2 * f_vals[3] +  f1_2 * f_vals[2] + f4_19 * f_vals[4];
    r[4] = f0_2 * f_vals[4] +  f1_2 * f_vals[3] +    f_vals[2] * f_vals[2];

    for(int i = 0; i < 5; i++)
    {
        r[i] &= mask;
        carry = r[i] >> 51;
        if(i < 4)
            r[i+1] += carry;
        else 
            r[0] += 19ULL * carry;
    }

    carry = r[0] >> 51;
    r[0] &= mask;
    r[1] += carry;
    carry = r[1] >> 51;
    r[1] &= mask;
    r[2] += carry;

    for(int i = 0; i < 5; i++)
    {
        h[i] = (uint64_t) r[i];
    }
}