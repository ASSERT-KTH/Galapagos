fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f10[10];
    int32_t g10[10];
    int32_t g19[10];
    int32_t f2[10];
    int64_t fg[100];
    int64_t h10[10];
    int64_t carry10[10];

    for (int i = 0; i < 10; i++)
    {
        f10[i] = f[i];
        g10[i] = g[i];
        g19[i] = 19 * g[i];
        f2[i] = 2 * f[i];
        
        h10[i] = 0;
        carry10[i] = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int index = i + j;
            if (i % 2 == 1 && j % 2 == 1)
                fg[index] = f2[i / 2] * (int64_t) g19[j / 2];
            else if (i % 2 == 1 || j % 2 == 1)
                fg[index] = f10[i] * (int64_t) g19[j];
            else
                fg[index] = f10[i] * (int64_t) g10[j];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = i ; j <= (i+9); j++)
        {
           h10[i] += fg[j % 10]; 
        }
    }

    carry10[0] = (h10[0] + (int64_t)(1L << 25)) >> 26;
    h10[1] += carry10[0];
    h10[0] -= carry10[0] * ((uint64_t)1L << 26);

    for (int i = 4; i <= 8; i += 4)
    {
        carry10[i] = (h10[i] + (int64_t)(1L << 25)) >> 26;
        h10[(i+1) % 10] += carry10[i];
        h10[i] -= carry10[i] * ((uint64_t)1L << 26);

        carry10[(i+1) % 10] = (h10[(i+1) % 10] + (int64_t)(1L << 24)) >> 25;
        h10[(i+2) % 10] += carry10[(i+1) % 10];
        h10[(i+1) % 10] -= carry10[(i+1) % 10] * ((uint64_t)1L << 25);

        carry10[(i+9) % 10] = (h10[(i+9) % 10] + (int64_t)(1L << 24)) >> 25;
        h10[(i+10) % 10] += carry10[(i+9) % 10] * 19;
        h10[(i+9) % 10] -= carry10[(i+9) % 10] * ((uint64_t)1L << 25);

        carry10[(i+10) % 10] = (h10[(i+10) % 10] + (int64_t)(1L << 25)) >> 26;
        h10[(i+11) % 10] += carry10[(i+10) % 10];
        h10[(i+10) % 10] -= carry10[(i+10) % 10] * ((uint64_t)1L << 26);
    }

    for(int i=0;i<10;i++) {
        h[i] = (int32_t) h10[i];
    }

}