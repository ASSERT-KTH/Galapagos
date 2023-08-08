fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_temp[5], f_mul[4];
    uint128_t g_temp[5];
    uint64_t  r_res[5];
    uint64_t  carry;

    for (int i=0; i < 5; i++)
    {
        f_temp[i] = (uint128_t) f[i];
        g_temp[i] = (uint128_t) g[i];
        if(i<4) f_mul[i] = 19ULL * f_temp[i+1];
    }

    r[0] = f_temp[0] * g_temp[0] + f_mul[0] * g_temp[4] + f_mul[1] * g_temp[3] + f_mul[2] * g_temp[2] + f_mul[3] * g_temp[1];

    for(int i = 1; i <= 4; i++)
    {
        if (i != 4) 
            r[i] = f_temp[0] * g_temp[i] +    f_temp[1] * g_temp[i-1] +    f_temp[2] * g_temp[i-2] + f_mul[2] * g_temp[4-(i-2)] + f_mul[3] * g_temp[4-(i-2)+1];
        else
            r[i] = f_temp[0] * g_temp[i] +    f_temp[1] * g_temp[i-1] +    f_temp[2] * g_temp[i-2] +    f_temp[3] * g_temp[i-3] +    f_temp[4] * g_temp[0];
    }

    for(int i = 0; i < 5; i++)
    {
        r_res[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if(i != 4)  r[i+1]+= carry;
    }

    r_res[0]   += 19ULL * carry;
    carry  = r_res[0] >> 51;
    r_res[0]   &= mask;

    for(int i=1; i < 5; i++)
    {
        r_res[i]+= carry;
        carry  = r_res[i] >> 51;
        r_res[i]&= mask;
    }

    for (int i=0; i < 5; i++){
        h[i] = r_res[i];
    }
}