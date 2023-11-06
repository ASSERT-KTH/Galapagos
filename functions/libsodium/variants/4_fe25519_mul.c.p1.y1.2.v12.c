Variant 1:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_val[5], g_val[5];
    uint64_t r_val[5], carry;

    for (int i = 0; i < 5; ++i) 
    {
        f_val[i] = (uint128_t) f[i];
        g_val[i] = (uint128_t) g[i];
    }

    uint128_t f19[4] = {19ULL * f_val[1], 19ULL * f_val[2], 19ULL * f_val[3], 19ULL * f_val[4]};

    uint128_t r[5] = {f_val[4] * g_val[0] + f19[3] * g_val[1] + f19[2] * g_val[2] 
                     + f19[1] * g_val[3] + f19[0] * g_val[4]};

    for (int i = 1; i < 5; ++i) 
    {
        r[i] = f_val[(5 - i) % 5] * g_val[0] + f_val[(4 - i) % 5] * g_val[1] 
              + f_val[(3 - i) % 5] * g_val[2] + f19[(2 - i) % 4] * g_val[3] 
              + f19[(1 - i) % 4] * g_val[4];
    }
   
    for (int i = 0; i < 5; ++i) 
    {
        r_val[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[(i+1)%5]  += carry;
        r_val[i]  = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[((i+1)%5)+1]  += carry;
       .
       .
        r_val[(i+2)%5] += r[((i+1)%5] % 2);
        h[i] = r_val[i];
    }
}

Variant 2:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_vals[5], g_vals[5], f_vals_19[4];
    uint64_t fin_r[5], carries;

    for(int i=0; i<5; i++){
        f_vals[i] = f[i];
        g_vals[i] = g[i];
    }
   
    for(int i=1; i<5; i++){
        f_vals_19[i-1] = 19 * f[i];
    }

    for(int i=0; i<5; i++){
        r[i] = f_vals[(5-i)%5]*g_vals[0] + f_vals[(6-i)%5]*g_vals[1]
             + f_vals[(7-i)%5]*g_vals[2] + f_vals_19[(3-i)%4]*g_vals[3] 
             + f_vals_19[(4-i)%4]*g_vals[4];

        fin_r[i] = r[i] & mask;
        carries = r[i] >> 51;
        r[i] += carries;
        fin_r[i] = r[i]&(mask);
        carries = r[i] >> 51;
        r[(i+1)%5] += carries;
        if(i<2)
        {
            fin_r[(i+2)%5] += carries;
        }
    }
}
