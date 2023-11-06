void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], temp;
    uint128_t f_mul[5];
    uint128_t g_mul[5];
    uint64_t  r_final[5];
    uint64_t  carry;
    int i;

    for(i=0;i<5;i++)
    {
       f_mul[i] = (uint128_t) f[i];
       g_mul[i] = (uint128_t) g[i];
    }

    f_mul[1] *= 19ULL; f_mul[2] *= 19ULL; f_mul[3] *= 19ULL; f_mul[4] *= 19ULL;

    r[0] = f_mul[0] * g_mul[0] + f_mul[1] * g_mul[4] + f_mul[2] * g_mul[3] + f_mul[3] * g_mul[2] + f_mul[4] * g_mul[1];
    r[1] = f_mul[0] * g_mul[1] + f[1] * g_mul[0] + f_mul[2] * g_mul[4] + f_mul[3] * g_mul[3] + f_mul[4] * g_mul[2];
    r[2] = f_mul[0] * g_mul[2] + f[1] * g_mul[1] + f[2] * g_mul[0] + f_mul[3] * g_mul[4] + f_mul[4] * g_mul[3];
    r[3] = f_mul[0] * g_mul[3] + f[1] * g_mul[2] + f[2] * g_mul[1] + f[3] * g_mul[0] + f_mul[4] * g_mul[4];
    r[4] = f_mul[0] * g_mul[4] + f[1] * g_mul[3] + f[2] * g_mul[2] + f[3] * g_mul[1] + f[4] * g_mul[0];

    for(i=0;i<5;i++)
    {
        r_final[i] = ((uint64_t)r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        if(i<4) r[i+1] += carry;
    }

    temp = r_final[0] + 19ULL * (uint64_t) (r_final[4] >> 51);
    r_final[0] = ((uint64_t) temp) & mask;
    r_final[1] += (uint64_t) (temp >> 51);

    // transfer results to function arguments   
    for(i=0;i<5;i++)
        h[i] = r_final[i];
}