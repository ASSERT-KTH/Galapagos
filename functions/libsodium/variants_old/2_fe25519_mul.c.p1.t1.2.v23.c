fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_val[5], g_val[5], temp[5], r[5];
    uint64_t r_val[5], carry;

    for (int i = 0; i < 5; i++)
    {
        f_val[i] = (uint128_t)f[i];
        g_val[i] = (uint128_t)g[i];
        r[i] = 0;
    }

    for (int i = 0; i < 5; i++)
    {
        temp[i] = i > 0 ? 19ULL*f_val[i] : 0;

        for(int j = 0; j < 5; j++)
        {
            uint128_t g_index = (5 + j - i)%5;
            r[i] += i > 0 ? f_val[j]*g_val[g_index] + temp[j] : f_val[j]*g_val[g_index];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        r_val[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        r[(i+1)%5] += carry;
        r_val[i] &= mask;
        if (i == 3) r[0] += 19ULL*carry;
        if (i < 4) 
        {
            carry = r_val[i] >> 51;
            r_val[i] &= mask;
            r_val[i+1] += carry;
        }
        h[i] = r_val[i];
    }
}