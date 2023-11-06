void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t f0g0, f0g1, ..., f9g9_38;
    int32_t f0, f1, ..., f9, g0, ..., g9; 
    int32_t f1_2, ..., f9_2, g1_19, ..., g9_19;

    for(int i = 0; i < 10; i++) 
    {
       f[i] = f[i];
       g[i] = g[i];

       if(i%2==0) g[i] *= 19;
       else g[i+1] *= 2;
    }

    for(int i = 0; i < 10; i++) 
    {
        for(int j = 0; j < 10; j++) 
        {
            f[i]g[j] = f[i]*g[j];
        }
    }

    for(int i = 0; i < 10; i++)
    {
        carry=i = (hi+(int64_t)(1L<<(25+(-25*((i+1)%2))))) >> (26-(-25*((i+1)%2)));
        hj+1 = ((i+1)%2==0) ? carry[i] : carry[i] * 19;
        hi = ((i+1)%2==0) ? hi - carry[i] * ((uint64_t) 1L << (26-(-25*((i+1)%2)))) : hi - carry[i] * ((uint64_t) 1L << (26-(-25*((i+1)%2))));
    }

    for(int i = 0; i < 10; i++) 
    {
        h[i] = (int32_t)hi;
    }
}
