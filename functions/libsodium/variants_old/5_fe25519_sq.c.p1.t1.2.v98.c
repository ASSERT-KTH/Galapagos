void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t fv[5];
    uint64_t fvv[17];
    uint64_t  tmp, carry;

    for (int i =0; i<5; i++)
        fv[i] = (uint128_t)f[i];
    
    fv[2] <<= 1;
    fv[1] <<= 1;

    for (int i =1; i<4; i++)
        fvv[i+12] = 38ULL * fv[i];
    fvv[16] = fv[3] * 19;

    fv[1]= (fv[3]*19);

    r[0] = fv[3]*fv[3] + fv[1]*fv[4] + fv[0]*fv[0];
    r[1] = fv[1]*fv[1] + fv[2]*fv[4] + fv[0]*fv[1];
    r[2] = fv[2]*fv[2] + fv[0]*fv[2] + fv[1]*fv[4];
    r[3] = fv[0]*fv[3] + fv[1]*fv[2] + fvv[16]*fv[4];
    r[4] = fv[0]*fv[4] + fv[1]*fv[3] + fv[2]*fv[2];

    for (int i=0; i<5; i++)
    {   
        tmp     = ((uint64_t) r[i]) & mask;
        carry   = (uint64_t) (r[i] >> 51);
        r[(i+1)%5] += carry;
        r[i]    = tmp;
    }

    r[0] += 19ULL * ((((uint64_t) r[0]) >> 51));
    r[0] &= mask;
    r[1] += ((*(uint64_t*)&r[0]) >> 51);
    r[1] &= mask;
    r[2] += ((*(uint64_t*)&r[1]) >> 51);

    for (int i=0; i<5; i++)
        h[i] = r[i];
}