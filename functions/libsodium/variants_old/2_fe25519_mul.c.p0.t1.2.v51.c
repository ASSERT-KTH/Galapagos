fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5]; 
    uint128_t f[5], g[5]; 
    uint128_t f_mul[4]; 
    uint64_t  r_carry[5]; 
    uint64_t  carry;

    for(int i=0 ; i<5 ; i++){
        f[i] = (uint128_t) f[i];
        g[i] = (uint128_t) g[i];
    }

    for(int i=1 ; i<5 ; i++){
        f_mul[i-1] = 19ULL * f[i];  
    }

    r[0] = f[0] * g[0] + f_mul[3] * g[4] + f_mul[2] * g[3] + f_mul[1] * g[2] + f_mul[0] * g[1];
    r[1] = f[0] * g[1] +        f[1] * g[0] + f_mul[3] * g[4] + f_mul[2] * g[3] + f_mul[1] * g[2];
    r[2] = f[0] * g[2] +        f[1] * g[1] +        f[2] * g[0] + f_mul[3] * g[4] + f_mul[2] * g[3];
    r[3] = f[0] * g[3] +        f[1] * g[2] +        f[2] * g[1] +        f[3] * g[0] + f_mul[3] * g[4];
    r[4] = f[0] * g[4] +        f[1] * g[3] +        f[2] * g[2] +        f[3] * g[1] +        f[4] * g[0];

    for(int i=0;, i<5 ; i++)
    {
        r_carry[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if( i != 4 ) {
            r[i+1] += carry;
        }
    }
    r_carry[0] += (19ULL * carry);
    for(int i=1 ; i<4 ; i++)
    {
        carry  = r_carry[i] >> 51;
        r_carry[i]   &= mask;
        r_carry[i+1] += carry;
    }

    for(int i=0 ; i<5 ; i++)
    {
        h[i] = r_carry[i];
    }

}