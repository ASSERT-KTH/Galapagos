fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int i, j;

    int64_t h_temp[10] = {0};
    
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j <= i; ++j)
        {
            h_temp[i] += (((int64_t)f[j]) * g[i - j]);
        }

        if (i < 9)
        {
            h_temp[i] += 38 * ((int64_t)f[i + 1]) * g[9];
        }
    }

    h_temp[9] *= 19;
    
    for (i = 0; i < 9; i++)
    {
        j = i + 1;
        while (j > 0)
        {
            uint64_t carry = h_temp[j - 1] >> 26;
            h_temp[j - 1] &= (1 << 26) - 1;
            h_temp[j] += carry;
            --j;
        }
    }
    
    for(i = 0; i < 10; ++i)
    {
        h[i] = h_temp[i];
    }
}