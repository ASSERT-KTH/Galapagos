fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t carry;
    uint128_t r0, r4, fx[5], r;
    uint64_t h_cache[5],r_i[5];

    for(int i=0; i<5; i++) {
        fx[i] = (uint128_t) f[i];
    }
       
    uint128_t fx_2[2] = { (fx[0]) << 1, (fx[1]) << 1 };
    uint128_t mfx[] = { 38ULL * fx[1], 38ULL * fx[2], 38ULL * fx[3], 19ULL * fx[3], 19ULL * fx[4] };

    const uint128_t fir[] = { mfx[0] * fx[4], mfx[1] * fx[3], mfx[2] * fx[4], mfx[3], mfx[4] };
    const uint128_t sec[] = { fx_2[0] * fx[1], fx[2] * fx[4], fx[1] * fx[1], fx_2[0] * fx[3], fx_2[1] * fx[2], fx_2[0] * fx[4], fx_2[1] * fx[3], fx[2] * fx[2] };
    
    const uint128_t to_sum[5][3] = {
        { fx[0]*fx[0], fir[0], fir[1] },
        { sec[0], fir[2], fir[3] },
        { sec[1], sec[2], fir[2] },
        { sec[3], sec[4], sec[5] },
        { sec[6], sec[7], fir[4] } 
    };

    for(int i = 0; i < 5; i++)
    {
        r = 0;
        for(int j=0; j<3; j++)
        {
             r += to_sum[i][j];
        }
        r_i[i] = ((uint64_t) r) & mask;
        carry = (uint64_t) (r >> 51);
        if (i != 4)
        {
            r_i[i+1] +=carry;
        }
        else
        {
            r_i[0]+= 19ULL * carry;
        }
    }

    for(int i = 0 ; i < 3 ; i++)
    {
        carry  = h_cache[i] >> 51;
        h_cache[i]   &= mask;
        h_cache[i+1]+= carry;
    }

    h_cache[2] += h_cache[0] >> 51;
    h_cache[0] &= mask;

    for(int j = 0 ; j < 5 ; j++) 
    {
        h[j] = h_cache[j];
    }
}