fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5] = {0}, f_red[5], f_mul[5];
    uint64_t carrying = 0;

    for(uint8_t wi = 0;wi < 5;wi++)
    {
        f_red[wi] = (uint128_t)f[wi];
    }

    f_mul[0] = f_red[0] << 1;
    f_mul[1] = f_red[1] << 1;

    f_mul[2] = 38ULL * f_red[1];
    f_mul[3] = 38ULL * f_red[2];
    f_mul[4] = 38ULL * f_red[3];

    f_mul[5] = 19ULL * f_red[3];
    f_mul[6] = 19ULL * f_red[4];

    r[0] =   f_red[0] * f_red[0] + f_mul[2] * f_red[4] + f_mul[3] * f_red[3];
    r[1] = f_mul[0] * f_red[1] + f_mul[3] * f_red[4] + f_mul[5] * f_red[3];
    r[2] = f_mul[0] * f_red[2] +    f_red[1] * f_red[1] + f_mul[4] * f_red[4];
    r[3] = f_mul[0] * f_red[3] +  f_mul[1] * f_red[2] + f_mul[6] * f_red[4];
    r[4] = f_mul[0] * f_red[4] +  f_mul[1] * f_red[3] +    f_red[2] * f_red[2];

    for(uint8_t wi = 0; wi < 5; wi++)
    {
        h[wi] = ((uint64_t) r[wi]) & mask;
        carrying  = (uint64_t) (r[wi] >> 51);
        if(wi < 4)
        {
            r[wi+1] += carrying;
        }
    }

    h[0]   += 19ULL * carrying;
    carrying  = h[0] >> 51;
    h[0]   &= mask;

    for(uint8_t wi = 1; wi < 3; wi++)
    {
        h[wi]   += carrying;
        carrying  = h[wi] >> 51;
        h[wi]   &= mask;
    }
}