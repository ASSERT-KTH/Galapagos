fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], r_mod[5];
    uint128_t f_cast[5], f_mul[7];
    uint64_t carry;
    int i;

    for(i = 0; i < 5; i++)
        f_cast[i] = (uint128_t) f[i];

    f_mul[0] = f_cast[0] << 1;
    f_mul[1] = f_cast[1] << 1;

    for(i = 1; i <= 3; i++)
        f_mul[i+1] = 38ULL * f_cast[i];

    f_mul[5] = 19ULL * f_cast[3];
    f_mul[6] = 19ULL * f_cast[4];

    r[0] =   f_cast[0] * f_cast[0] + f_mul[4] * f_cast[4] + f_mul[2] * f_cast[2];
    r[1] = f_mul[0] * f_cast[1] + f_mul[5] * f_cast[5] + f_mul[6] * f_cast[4];
    r[2] = f_mul[0] * f_cast[2] + f_cast[1] * f_cast[1] + f_mul[4] * f_mul[4];
    r[3] = f_mul[0] * f_cast[3] + f_mul[1] * f_cast[2] + f_mul[6] *  f_mul[6];
    r[4] = f_mul[0] * f_cast[4] +  f_mul[1] * f_cast[3] + f_cast[2] * f_cast[2];

    carry  = 0ULL;

    for(i = 0; i < 5; ++i)
    {
        r[i]   += carry;
        r_mod[i]    = ((uint64_t)r[i]) & mask;
        carry  = (uint64_t)(r[i]>>51);
    }

    r_mod[0] += 19ULL * carry;

    for(i = 0; i < 2; ++i)
    {
        carry  = r_mod[i] >> 51;
        r_mod[i]  &= mask;
        r_mod[i+1] += carry;
    }

    for(i = 0; i < 5; ++i)
        h[i] = r_mod[i];
}
