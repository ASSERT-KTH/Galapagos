void fe25519_sq(fe25519 h, const fe25519 f) 
{
    fe25519 tmp;
    
    for(int i = 0; i < 10; i++)
    {
        tmp[i] = f[i];
    }

    for(int i = 0; i < 10; i++) 
    {
        tmp[i] = tmp[i] << 1;
    }
    
    int64_t carry[10] = {0};
    int64_t prod[10]  = {0};

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i + j < 10) 
            {
                prod[i + j] += (int64_t)(tmp[i]) * f[j];
            } 
            else if(i + j < 19) 
            {
                carry[i + j - 10] += 38 * (int64_t)(tmp[i]) * f[j];
            }
        }
    }

    for(int i = 0; i < 10; i++) 
    {
        if(i > 0) 
        { 
            prod[i - 1] += carry[i];
        } 
        prod[i] += carry[0];
    }
   
    for(int i = 0; i < 9; i++)  
    { 
        carry[i] = (prod[i] >> ((i & 1) ? 25 : 26));
        h[i] = (int32_t)(prod[i] - (carry[i] << ((i & 1) ? 25 : 26)));
    }  
    h[9] = (int32_t)(prod[9]);
    
    int32_t carry9 = h[9] >> 25;
    h[9] -= carry9 << 25;
    h[0] += 19 * carry9;
    
    int32_t carry0 = h[0] >> 26;
    h[0] -= carry0 << 26;
    h[1] += carry0;
}