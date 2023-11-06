fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_sq[5];
    uint128_t rules[5];
    uint64_t r_p[5];
    uint64_t carry;

    for(int i = 0; i < 5; ++i)
    {
        f_sq[i] = (uint128_t)f[i];
    }

    f_sq[0] <<= 1;
    f_sq[1] <<= 1;

    rules[1] = 38ULL * f_sq[1];
    rules[2] = 38ULL * f_sq[2];
    rules[3] = 38ULL * f_sq[3];

    rules[3] = 19ULL * f_sq[3];
    rules[4] = 19ULL * f_sq[4];

    r[0] =   f_sq[0] * f_sq[0] + rules[1] * f_sq[4] + rules[2] * f_sq[3];
    r[1] = f_sq[0] * f_sq[1] + rules[2] * f_sq[4] + rules[3] * f_sq[3];
    r[2] = f_sq[0] * f_sq[2] +    f_sq[1] * f_sq[1] + rules[3] * f_sq[4];
    r[3] = f_sq[0] * f_sq[3] +  f_sq[1] * f_sq[2] + rules[4] * f_sq[4];
    r[4] = f_sq[0] * f_sq[4] +  f_sq[1] * f_sq[3] +    f_sq[2] * f_sq[2];

    for(int i = 0; i < 5; ++i)
    {
        r_p[i] = ((uint64_t) r[i]) & mask;
        carry   = (uint64_t) (r[i] >> 51);
        int next_number = i + 1 >= 5 ? 0 : i + 1; 
        r[next_number]  += carry;

    }
    r_p[0] += 19ULL * carry;
    
    for(int i = 0; i < 5; ++i)
    {
        carry = r_p[i] >> 51;
        r_p[i] &= mask;
        int next_number = i + 1 >= 5 ? 0 : i + 1; 
        r_p[next_number] += carry;

        h[i] = r_p[i];
    }
}