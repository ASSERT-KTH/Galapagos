fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_values[5], f_values_19[4], g_values[5];
    uint64_t  results[5];
    uint64_t  carry;
    
    for (int i = 0; i < 5; i++)
    {
        f_values[i] = (uint128_t) f[i];
        g_values[i] = (uint128_t) g[i];
    }
    
    for (int i = 0; i < 4; i++)
    {
        f_values_19[i] = 19ULL * f_values[i+1];
    }
    
    r[0] = f_values[0] * g_values[0] + f_values_19[0] * g_values[4] + f_values_19[1] * g_values[3] + f_values_19[2] * g_values[2] + f_values_19[3] * g_values[1];
    r[1] = f_values[0] * g_values[1] +    f_values[1] * g_values[0] + f_values_19[1] * g_values[4] + f_values_19[2] * g_values[3] + f_values_19[3] * g_values[2];
    r[2] = f_values[0] * g_values[2] +    f_values[1] * g_values[1] +    f_values[2] * g_values[0] + f_values_19[2] * g_values[4] + f_values_19[3] * g_values[3];
    r[3] = f_values[0] * g_values[3] +    f_values[1] * g_values[2] +    f_values[2] * g_values[1] +    f_values[3] * g_values[0] + f_values_19[3] * g_values[4];
    r[4] = f_values[0] * g_values[4] +    f_values[1] * g_values[3] +    f_values[2] * g_values[2] +    f_values[3] * g_values[1] +    f_values[4] * g_values[0];
    
    for(int i = 0; i < 5; i++)
    {
        results[i] = ((uint64_t)r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
        
        if (i == 0 || i == 1)
        {
            carry  = results[i] >> 51;
            results[i]    &= mask;
            results[i+1]  += carry;
        }
    }
    
    for(int i = 0; i < 5; ++i)
    {
        h[i] = results[i];
    }

}