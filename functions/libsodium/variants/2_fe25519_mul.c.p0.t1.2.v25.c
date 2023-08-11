fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], f_vals[5], g_vals[5];
    
    uint64_t carry;
    
    for (int i = 0; i < 5; i++) 
    {
        f_vals[i] = (uint128_t) f[i];
        g_vals[i] = (uint128_t) g[i];
    }
    
    for(int j = 0; j < 5; j++) 
    {
        r[j] = f_vals[0] * g_vals[j] + 19ULL * 
        ((f_vals[(j + 4) % 5] * g_vals[1]) + 
        (f_vals[(j + 3) % 5] * g_vals[2]) + 
        (f_vals[(j + 2) % 5] * g_vals[3]) + 
        (f_vals[(j + 1) % 5] * g_vals[4]));
    }
    
    for(int k = 0; k < 5; k++) 
    {
        h[k] = (uint64_t)r[k] & mask;

        carry = (uint64_t) (r[k] >> 51);
        r[(k + 1) % 5] += carry;

        carry = h[k] >> 51;
        h[k] &= mask;
        h[(k + 1) % 5] += carry;
    }
    
}