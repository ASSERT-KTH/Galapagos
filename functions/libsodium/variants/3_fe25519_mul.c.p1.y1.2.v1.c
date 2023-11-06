Variant 1: Unrolled loop


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int i,j;
    int32_t f[10], g[10], fg[10][10];
    int64_t h[10];
    
    for (i = 0; i < 10; i++)
    {
        f[i] = f[i];
        g[i] = g[i];
    }

    for( i = 0; i < 10; i++)
    {
        for( j=0; j < 10; j ++)
        {
            fg[i][j] = f[i] * (int64_t) g[j];
        }
    }

    for (i=0; i < 10; i++)
    {
        h[i] = 0;
        for(j=0; j < 10; j ++)
        {
            h[i] += fg[i][j];
        }
        h[i] = (h[i] + (int64_t)(1L << 25)) >> 26; 
    }

    for (i=0; i < 9; i++)
    {
        h[i+1] += (h[i] + (int64_t)(1L << 25)) >> 26;
        h[i] -= (h[i-1] + 19 * ((uint64_t) 1L << 25)) >> 26 * ((uint64_t) 1L << 26);
    }
    
    for (i = 0; i < 10; i++)
    {
        h[i] = (int32_t) h[i]
    }
}


Variant 2: Switched multipliers


fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t i;
    int64_t fy[10], gy[10], carry[10], h_[10];
    const int64_t multiplier[10] = {19, 2, 19, 2, 19, 2, 19, 2, 19, 2};

    for(i = 0; i < 10; i++)
    {
         fy[i] = f[i];
         gy[i] = g[i] * multiplier[i];
    }

    for(i = 0; i < 10; i++)
    {
         h_[i] = 0;
         for(int j = 0; j < 10; j++)
         {
             h_[i] += fy[i] * gy[j];
         }
         h_[i] = (h_[i] + (int64_t)(1L << 25)) >> 26;

         if((i & 1) == 0)
             carry[i] = (h_[i] + (int64_t)(1L << 25)) >> 26;
         else
             carry[i] = (h_[i] + (int64_t)(1L << 24)) >> 25;

         h[i] = (int32_t)(h_(i) + carry[i]);
    }
}
