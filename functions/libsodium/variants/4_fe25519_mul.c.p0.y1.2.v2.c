void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_val[5], f19_val[4];
    uint128_t g_val[5];
    uint64_t  h_val[5];
    uint64_t  carry;

    for (int i=0; i<5; i++) 
    {
        f_val[i] = (uint128_t) f[i];
        g_val[i] = (uint128_t) g[i];
    }

    for (int i=0; i<4; i++)
          f19_val[i] = 19ULL * f_val[i+1];
    
    r[0] = f_val[0] * g_val[0] + f19_val[0] * g_val[4] + f19_val[1] * g_val[3] + f19_val[2] * g_val[2] + f19_val[3] * g_val[1];
    r[1] = f_val[0] * g_val[1] + f_val[1] * g_val[0] + f19_val[1] * g_val[4] + f19_val[2] * g_val[3] + f19_val[3] * g_val[2];
    r[2] = f_val[0] * g_val[2] + f_val[1] * g_val[1] + f_val[2] * g_val[0] + f19_val[2] * g_val[4] + f19_val[3] * g_val[3];
    r[3] = f_val[0] * g_val[3] + f_val[1] * g_val[2] + f_val[2] * g_val[1] + f_val[3] * g_val[0] + f19_val[3] * g_val[4];
    r[4] = f_val[0] * g_val[4] + f_val[1] * g_val[3] + f_val[2] * g_val[2] + f_val[3] * g_val[1] + f_val[4] * g_val[0];

    for (int i = 0; i < 5; i++) 
    {
        h_val[i] = ((uint64_t) r[i]) & mask;

        if (i != 4)
        { 
            carry  = (uint64_t) (r[i] >> 51);
            r[i+1] += carry;
        }

        if (i == 4) 
        {
            h_val[0] += 19ULL * ((uint64_t) (r[4] >> 51));
            carry     = h_val[0] >> 51;
            h_val[0] &= mask;
            h_val[1] += carry;
        }
        else if (i == 0)
        {
            carry    = h_val[1] >> 51;
            h_val[1] &= mask;
            h_val[2] += carry;
        }
    
        h[i] = h_val[i];
    } 
}