void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t h0,h1,h2,h3,h4,h5,h6,h7,h8,h9;
    int64_t t[10];
    for(int i=0;i<10;i++)
    {
        t[i] = 2 * f[i];
    }
    int64_t f0f0    = f[0] * (int64_t) f[0];
    int64_t f1f1_2  = t[1] * (int64_t) f[1];
    int64_t f2f2    = f[2] * (int64_t) f[2];
    int64_t f3f3_2  = t[3] * (int64_t) f[3];
    int64_t f4f4    = f[4] * (int64_t) f[4];
    int64_t f5f5_38 = t[5] * (int64_t) (38 * f[5]);
    int64_t f6f6_19 = f[6] * (int64_t) (19 * f[6]);
    int64_t f7f7_38 = f[7] * (int64_t) (38 * f[7]);
    int64_t f8f8_19 = f[8] * (int64_t) (19 * f[8]);
    int64_t f9f9_38 = f[9] * (int64_t) (38 * f[9]);

    t[0] = f[0] << 1;
    t[1] = f[1] << 1;
    t[3] = f[3] << 1;
    t[4] = f[4] << 1;

    int64_t f0f1_2  = t[0] * (int64_t) f[1];
    int64_t f0f2_2  = t[0] * (int64_t) f[2];
    int64_t f0f3_2  = t[0] * (int64_t) f[3];
    int64_t f0f4_2  = t[0] * (int64_t) f[4];
    int64_t f0f5_2  = t[0] * (int64_t) f[5];
    int64_t f0f6_2  = t[0] * (int64_t) f[6];
    int64_t f0f7_2  = t[0] * (int64_t) f[7];
    int64_t f0f8_2  = t[0] * (int64_t) f[8];
    int64_t f0f9_2  = t[0] * (int64_t) f[9];
    
    t[2] = f[0]+f[5];
    h0 = f0f0 + t[2]; 

    
    
    
    
    
    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    h[3] = (int32_t) h3;
    h[4] = (int32_t) h4;
    h[5] = (int32_t) h5;
    h[6] = (int32_t) h6;
    h[7] = (int32_t) h7;
    h[8] = (int32_t) h8;
    h[9] = (int32_t) h9;
}