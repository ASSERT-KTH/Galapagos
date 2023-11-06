void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_x[5];
    uint128_t f_mul[4];
    uint128_t g_x[5];
    unsigned int i;
    uint64_t  carry, temp[5];

    for (i = 0; i < 5; i++)
    {
        f_x[i] = (uint128_t) f[i];
        g_x[i] = (uint128_t) g[i];
    }
    
    for (i = 1; i < 5; i++)
    {
        f_mul[i - 1] = 19ULL * f_x[i];
    }
    
    r[0] = f_x[0] * g_x[0] + f_mul[0] * g_x[4] + f_mul[1] * g_x[3] + f_mul[2] * g_x[2] + f_mul[3] * g_x[1];
    r[1] = f_x[0] * g_x[1] + f_x[1] * g_x[0] + f_mul[1] * g_x[4] + f_mul[2] * g_x[3] + f_mul[3] * g_x[2];
    r[2] = f_x[0] * g_x[2] + f_x[1] * g_x[1] + f_x[2] * g_x[0] + f_mul[2] * g_x[4] + f_mul[3] * g_x[3];
    r[3] = f_x[0] * g_x[3] + f_x[1] * g_x[2] + f_x[2] * g_x[1] + f_x[3] * g_x[0] + f_mul[3] * g_x[4];
    r[4] = f_x[0] * g_x[4] + f_x[1] * g_x[3] + f_x[2] * g_x[2] + f_x[3] * g_x[1] + f_x[4] * g_x[0];
    
    for (i = 0; i < 5; i++)
    {
        temp[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[(i + 1) % 5] += carry; 
    }
  
    temp[0] += 19ULL * carry;
    carry = temp[0] >> 51;
    temp[0] &= mask;
    
    for (i = 1; i < 4; i++)
    {
        temp[i] += carry;
        carry = temp[i] >> 51;
        temp[i] &= mask;
    }
  
    for (i = 0; i < 5; i++)
    {
        h[i] = temp[i];
    }
}