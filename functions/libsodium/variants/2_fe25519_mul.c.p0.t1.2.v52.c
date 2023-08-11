fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t r[5], fg[5], frac[5];
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t  carry, r_fin[5];

    for(int i=0; i<5; i++)
    {
        fg[i] = (uint128_t) f[i];
        frac[i] = (uint128_t) g[i];
    }

    for(int i=1; i<5; i++)
    {
        fg[i] *= 19ULL;
    }

    r[0] = fg[0] * frac[0] + fg[1] * frac[4] + fg[2] * frac[3] + fg[3] * frac[2] + fg[4] * frac[1];
    r[1] = fg[0] * frac[1] + f[1] * frac[0] + fg[2] * frac[4] + fg[3] * frac[3] + fg[4] * frac[2];
    r[2] = fg[0] * frac[2] + f[1] * frac[1] + f[2] * frac[0] + fg[3] * frac[4] + fg[4] * frac[3];
    r[3] = fg[0] * frac[3] + f[1] * frac[2] + f[2] * frac[1] + f[3] * frac[0] + fg[4] * frac[4];
    r[4] = fg[0] * frac[4] + f[1] * frac[3] + f[2] * frac[2] + f[3] * frac[1] + f[4] * frac[0];

    for(int i=0; i<5; i++)
    {
        r_fin[i]    = (r[i]) & mask;    
        carry  = (uint64_t) (r[i] >> 51);

        if(i != 4) { r[i+1] += carry; }
        else
        {
            r_fin[0] += 19ULL * carry;
            carry  = r_fin[0] >> 51;
            r_fin[0] &= mask;
            r_fin[1] += carry;
            carry  = r_fin[1] >> 51;
            r_fin[1] &= mask;
            r_fin[2] += carry;
        }     
    }
    for(int i=0; i<5; i++)
    {
      h[i] = r_fin[i];
    }
}