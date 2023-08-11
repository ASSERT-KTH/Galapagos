void fe25519_sq(fe25519 h, const fe25519 f)
{
    size_t i;
    int32_t new_f[10];
    int64_t t[10];
    
    for(i = 0; i < 10; i++) 
    {
        new_f[i] = 2 * f[i];
    }

    for(i = 0; i < 5; i++) 
    {
        int64_t tmp = (int64_t) new_f[i] * new_f[i];
        t[i] = (tmp << 1) - tmp;
    }

    for(i = 0; i < 5; i++)
    {
        int32_t j;
        for(j = i + 1; j < 10; j += 2) 
        {
            int64_t temp = (int64_t) 38 * new_f[i] * new_f[j];
            t[i + j / 2] += temp;
            t[i + j / 2 + 1] += temp;
        }
    }

    int64_t carry[10];
    for(i = 0; i < 10; i++) 
    {
        t[i] += ((int64_t)1 << (26 - (i % 2))) / 2;
        carry[i] = t[i] >> (26 - (i % 2));
        t[i] -= carry[i] << (26 - (i % 2));
    }
    
    t[0] += 19 * carry[9];
    t[1] += carry[0];
    
    for(i = 0; i < 10; i++) 
    {
        h[i] = (int32_t)t[i];
    }
}