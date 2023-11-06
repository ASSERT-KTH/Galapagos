fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_vals[5];
    uint128_t g_vals[5];
    uint128_t f_vals_mult_19[4];
    uint64_t  r_vals[5];
    uint64_t  carry;

    for(int i=0; i<5; i++)
    {
        f_vals[i]=(uint128_t) f[i];
        g_vals[i]=(uint128_t) g[i];
    }
    
    for(int i=1; i<5; i++)
    {
         f_vals_mult_19[i-1]= 19ULL * f_vals[i];
    }

    r0 = f_vals[0] * g_vals[0] + f_vals_mult_19[3] * g_vals[4] + f_vals_mult_19[2] * g_vals[3] + f_vals_mult_19[1] * g_vals[2] + f_vals_mult_19[0] * g_vals[1];
    r1 = f_vals[0] * g_vals[1] + f_vals[1] * g_vals[0] + f_vals_mult_19[3] * g_vals[4] + f_vals_mult_19[2] * g_vals[3] + f_vals_mult_19[0] * g_vals[2];
    r2 = f_vals[0] * g_vals[2] + f_vals[1] * g_vals[1] + f_vals[2] * g_vals[0] + f_vals_mult_19[3] * g_vals[4] + f_vals_mult_19[1] * g_vals[3];
    r3 = f_vals[0] * g_vals[3] + f_vals[1] * g_vals[2] + f_vals[2] * g_vals[1] + f_vals[3] * g_vals[0] + f_vals_mult_19[2] * g_vals[4];
    r4 = f_vals[0] * g_vals[4] + f_vals[1] * g_vals[3] + f_vals[2] * g_vals[2] + f_vals[3] * g_vals[1] + f_vals[4] * g_vals[0];

    r_vals[0]= ((uint64_t) r0) & mask;
    carry= (uint64_t) (r0>>51);
    
    for(int i = 1; i < 5; i++)
    {
        switch(i)
        {
            case 1: r1 += carry; break;
            case 2: r2 += carry; break;
            case 3: r3 += carry; break;
            case 4: r4 += carry; break;
        }

        r_vals[i]=(uint64_t) (r_vals[i-1] >> 51);
        carry=(uint64_t) (r_vals[i-1] >> 51);
    }

    r_vals[0] += 19ULL * carry;
    carry=r_vals[0]>>51;
    r_vals[0]&=mask;
    r_vals[1]+=carry;
    carry=r_vals[1]>>51;
    r_vals[1]&=mask;
    r_vals[2]+=carry;

    for(int i = 0; i < 5; i++)
    {
        h[i] = r_vals[i];
    }
}
