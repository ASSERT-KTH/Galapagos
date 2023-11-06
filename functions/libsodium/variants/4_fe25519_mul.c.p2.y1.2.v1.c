void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t results[5];
    uint128_t f_vals[5];
    uint128_t f19_vals[4];
    uint128_t g_vals[5];
    uint64_t  res_vals[5];
    uint64_t  update_var;

    for(int i = 0; i < 5; i++)
    {
        f_vals[i] = (uint128_t) f[i];
        g_vals[i] = (uint128_t) g[i];

        if(i < 4)
        {
            f19_vals[i] = 19ULL * f[i+1];
        }
    }   

    results[0] = f_vals[0] * g_vals[0] + f19_vals[0] * g_vals[4] + f19_vals[1] * g_vals[3] + f19_vals[2] * g_vals[2] + f19_vals[3] * g_vals[1];
    results[1] = f_vals[0] * g_vals[1] + f_vals[1] * g_vals[0] + f19_vals[1] * g_vals[4] + f19_vals[2] * g_vals[3] + f19_vals[3] * g_vals[2];
    results[2] = f_vals[0] * g_vals[2] + f_vals[1] * g_vals[1] + f_vals[2] * g_vals[0] + f19_vals[2] * g_vals[4] + f19_vals[3] * g_vals[3];
    results[3] = f_vals[0] * g_vals[3] + f_vals[1] * g_vals[2] + f_vals[2] * g_vals[1] + f_vals[3] * g_vals[0] + f19_vals[3] * g_vals[4];
    results[4] = f_vals[0] * g_vals[4] + f_vals[1] * g_vals[3] + f_vals[2] * g_vals[2] + f_vals[3] * g_vals[1] + f_vals[4] * g_vals[0];

    for(int j = 0; j < 5; j++)
    {
        res_vals[j] = ((uint64_t) results[j]) & mask;
        update_var  = (uint64_t) (results[j] >> 51);

        if(j < 4)
        {
            results[j+1] += update_var;
        }

        if(j == 4)
        {
            res_vals[0] += 19ULL * update_var;
            update_var  = res_vals[0] >> 51;
            res_vals[0] &= mask;

            res_vals[1] += update_var;
            update_var  = res_vals[1] >> 51;
            res_vals[1] &= mask;

            res_vals[2] += update_var;
        }
    }

    for(int k = 0; k < 5; k++)
    {
        h[k] = res_vals[k];
    }
}