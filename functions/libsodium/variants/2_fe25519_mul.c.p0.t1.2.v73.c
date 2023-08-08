fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_values[5], g_values[5], f19_values[4];
    uint64_t carry;

    for(int i = 0; i < 5; i++)
    {
        f_values[i] = (uint128_t) f[i];
        g_values[i] = (uint128_t) g[i];
        if(i < 4)
            f19_values[i] = 19ULL * f_values[i+1];
    }

    r[0] = f_values[0] * g_values[0] + f19_values[3] * g_values[4] + f19_values[2] * g_values[3] + f19_values[1] * g_values[2] + f19_values[0] * g_values[1];
    r[1] = f_values[0] * g_values[1] +  f_values[1] * g_values[0] + f19_values[3] * g_values[4] + f19_values[2] * g_values[3] + f19_values[1] * g_values[2];
    r[2] = f_values[0] * g_values[2] +  f_values[1] * g_values[1] +  f_values[2] * g_values[0] + f19_values[3] * g_values[4] + f19_values[2] * g_values[3];
    r[3] = f_values[0] * g_values[3] +  f_values[1] * g_values[2] +  f_values[2] * g_values[1] +  f_values[3] * g_values[0] + f19_values[3] * g_values[4];
    r[4] = f_values[0] * g_values[4] +  f_values[1] * g_values[3] +  f_values[2] * g_values[2] +  f_values[3] * g_values[1] +  f_values[4] * g_values[0];
    
    for(int j = 0; j < 5; j++)
    {
        carry  = (uint64_t) (r[j] >> 51);
        r[j]  &= mask;
        if(j < 4)
            r[j+1] += carry;
        else
        {
            r[0] += 19ULL * carry;
            carry  = r[0] >> 51;
            r[0] &= mask;
            r[1] += carry;
            carry  = r[1] >> 51;
            r[1] &= mask;
            r[2] += carry;
        }
        h[j] = r[j];
    }
}
