fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fk[10], gk[10];
    int64_t hk [10];
    
    for(int k=0; k<10; ++k)
    {
        fk[k] = f[k];
        gk[k] = g[k]; 
    }

    int32_t g1_19 = 19 * gk[1];
    int32_t g2_19 = 19 * gk[2]; 
    int32_t g3_19 = 19 * gk[3];
    int32_t g4_19 = 19 * gk[4];
    int32_t g5_19 = 19 * gk[5];
    int32_t g6_19 = 19 * gk[6];
    int32_t g7_19 = 19 * gk[7];
    int32_t g8_19 = 19 * gk[8];
    int32_t g9_19 = 19 * gk[9];
    
    int32_t f1_2  = 2 * fk[1];
    int32_t f3_2  = 2 * fk[3];
    int32_t f5_2  = 2 * fk[5];
    int32_t f7_2  = 2 * fk[7];
    int32_t f9_2  = 2 * fk[9];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 1 || i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
                hk[i * j] = int64_t(fk[i] * f1_2);
            else if(j < 7 || j == 6)
                hk[i * j] = int64_t(gk[j] * 19);
            else hk[i * j] = int64_t(fk[i]*gk[j]);
        }
    }

    int64_t carry[10];  

    carry[0] = (hk[0] + (int64_t)(1L << 25)) >> 26;
    hk[1] += carry[0];
    hk[0] -= carry[0] * ((uint64_t) 1L << 26);
    // etc...

    for (int i = 1; i < 10; i++)
    {
        carry[i] = (hk[i] + (int64_t)(1L << 24)) >> 25;
        hk[i + 1] += carry[i];
        hk[i] -= carry[i] * ((uint64_t) 1L << 25);
    }   

    for (int i = 0; i < 10; i++)
    {
       h[i]=(int32_t) hk[i]; 
    }
}
