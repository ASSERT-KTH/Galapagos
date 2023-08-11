fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t component[5][5];
    uint128_t fprime[5];
    uint128_t gscale[5];
    uint64_t  hcarry;
    uint64_t  htemp;

    for(int i = 0; i < 5; i++){
        component[i][i] = ((uint128_t)f[i])  *  ((uint128_t)g[i]);
        fprime[i] = 19 * ((uint128_t)f[i]);
        gscale[i] = ((uint128_t)g[i]);
    }

    for(int i=0; i<5; i++)
    {
        r[i] = component[i][i];
        const int min_idx = (i+1)%5, max_idx = (i+4)%5;
        if(min_idx > max_idx)
            for(int j = min_idx; j < 5; j++)
                r[i] += fprime[j] * gscale[j-min_idx];
        else{
            for(int j = min_idx; j <= max_idx; j++)
                r[i] += fprime[j] * gscale[j-min_idx];
            for(int j= 0 ; j < max_idx; j++)
                r[i] += fprime[j] * gscale[5+j-min_idx];    
        }
    }

    for (int i=0; i<4; i++){
        h[i] = ((uint64_t) r[i]) & mask;
        hcarry  = (uint64_t) (r[i] >> 51);
        r[i+1]+= hcarry;
    }

    h[4] = ((uint64_t) r[4]) & mask;
    hcarry = (uint64_t) (r[4] >> 51);
    
    h[0] += 19ULL * hcarry;
    for (int i=0; i<2; i++){
        htemp  = ((uint64_t) h[i]) & mask;
        hcarry  = (uint64_t) (h[i] >> 51);
        h[i] = htemp;
        h[i+1]+= hcarry;
    }
}