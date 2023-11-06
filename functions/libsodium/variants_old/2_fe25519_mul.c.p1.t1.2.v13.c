
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5] = { 0 };
    uint128_t g_c[5] = { (uint128_t)g[0], (uint128_t)g[1], (uint128_t)g[2], (uint128_t)g[3], (uint128_t)g[4] };
    uint128_t f_prep[5] = { (uint128_t)f[0], 19ULL * (uint128_t)f[1], 
                            19ULL * (uint128_t)f[2], 
                            19ULL * (uint128_t)f[3], 
                            19ULL * (uint128_t)f[4] };
    uint64_t  carry;

    for(int i = 0, j = 0; i < 5; i++, j = (j + 4) & 4)
        for(int k = 0; k <= i; k++)
            r[i]+= (i == k ? 1ULL : 0ULL) * (uint128_t)f[k] * (uint128_t)g_c[j - k] + ((uint128_t)f_prep[k] * (uint128_t)g_c[j - k]);

    for(int m = 0; m < 4; m++) 
    {
        r[m + 1] += (r[m] >> 51);
        h[m] = ((uint64_t) (r[m] &= mask));

        // After the last round, need to propagate again ...
        if(m == 3)
        {
            carry = h[0] >> 51;
            h[0] &= mask;
            h[1] += carry;
            carry = h[1] >> 51;
            h[1] &= mask;
            h[2] += carry;
        }
    }

    h[4] = ((uint64_t) r[4]) & mask;
}
