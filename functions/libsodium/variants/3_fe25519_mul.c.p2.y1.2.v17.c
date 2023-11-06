void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{
    int32_t f_val[10];
    int32_t g_val[10];
    int32_t g_mult19[10];
    int32_t f_mult2[5];

    for(int i = 0; i < 10; i++)
    {
        f_val[i] = f[i];
        g_val[i] = g[i];

        if (i < 5) 
            f_mult2[i] = 2 * f_val[(2*i) + 1];
            
        if (i > 0)
            g_mult19[i] = 19 * g_val[i];
    }

    int64_t fg[100] = {0}; 
    int64_t h_val[10] = {0};
    uint64_t carry[10];
    int64_t t;

    for (size_t i = 0; i < 10; i++)
    { 
        for (size_t j = 0; j <= i; j++)
        { 
            t = i < 5 ? 2 : 1; // determine the multiplier

            if (i-j == j)
            { 
                fg[i] += t * f_val[i-j] * (int64_t)  g_val[j];
            } else
            { 
                fg[i] += t * (f_val[i-j] * (int64_t) g_mult19[j] + f_mult2[j] * (int64_t) g_val[i-j] * ((j != 0) ? 19 : 1) );
            }
        }
    }

    for (size_t i = 0; i < 10; i++)
    {
        h_val[i % 10] = fg[i] + fg[(i+9)%10] * 38 + ((i < 9) ? fg[i + 10] * 38  : 0);
        t = i == 9 ? 19 : 1; //determine carry boost

        carry[i % 10] = (i < 9) ? (uint64_t)((h_val[i] + (int64_t)(1ULL << 24)) >> 25) : (uint64_t)((h_val[i] + t*(int64_t)(1ULL << 24)) >> 25);
        
        h_val[(i+1)%10] += (int64_t) carry[i%10];
        h_val[i] -= carry[i%10] * ((uint64_t) 1ULL << 25);
    }

    for (size_t i = 0; i < 10; i++)
    { 
        h[i] = (int32_t) h_val[i];
    }
}