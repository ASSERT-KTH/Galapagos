fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_d[5];
    uint128_t mul_19_f_d[4];
    uint128_t g_d[5];
    uint64_t  r_d[5];
    uint64_t  carry;

    for(int idx=0; idx<5; idx++)
    {
        f_d[idx] = (uint128_t) f[idx];
        g_d[idx] = (uint128_t) g[idx];
    }

    for(int idx=1; idx<5; idx++)
    {
         mul_19_f_d[idx-1] = 19ULL * f_d[idx];
    }

    r[0] = f_d[0] * g_d[0] + mul_19_f_d[0] * g_d[4] + mul_19_f_d[1] * g_d[3] + mul_19_f_d[2] * g_d[2] + mul_19_f_d[3] * g_d[1];
    r[1] = f_d[0] * g_d[1] +    f_d[1] * g_d[0] + mul_19_f_d[1] * g_d[4] + mul_19_f_d[2] * g_d[3] + mul_19_f_d[3] * g_d[2];
    r[2] = f_d[0] * g_d[2] +    f_d[1] * g_d[1] +    f_d[2] * g_d[0] + mul_19_f_d[2] * g_d[4] + mul_19_f_d[3] * g_d[3];
    r[3] = f_d[0] * g_d[3] +    f_d[1] * g_d[2] +    f_d[2] * g_d[1] +    f_d[3] * g_d[0] + mul_19_f_d[3] * g_d[4];
    r[4] = f_d[0] * g_d[4] +    f_d[1] * g_d[3] +    f_d[2] * g_d[2] +    f_d[3] * g_d[1] +    f_d[4] * g_d[0];

    for(int idx=0; idx<5; idx++)
    {
        r_d[idx]    = ((uint64_t) r[idx]) & mask;
        carry  = (uint64_t) (r[idx] >> 51);
        r[item+1]    += carry;
    }
    
    r_d[0]   += 19ULL * carry;
    carry  = r_d[0] >> 51;
    r_d[0]   &= mask;
    r_d[1]   += carry;
    carry  = r_d[1] >> 51;
    r_d[1]   &= mask;
    r_d[2]   += carry;

    for(int idx=0; idx<5; idx++)
    {
        h[idx] = r_d[idx];
    }
}