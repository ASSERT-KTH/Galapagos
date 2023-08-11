fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4], f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];

    int32_t f0_2  = f0 << 1;
    int32_t f1_2  = f1 << 1;
    int32_t f2_2  = f2 << 1;
    int32_t f3_2  = f3 << 1;
    int32_t f4_2  = f4 << 1;
    int32_t f5_2  = f5 << 1;
    int32_t f6_2  = f6 << 1;
    int32_t f7_2  = f7 << 1;
    int32_t f5_38 = 38 * f5; 
    int32_t f6_19 = f6 * 19; 
    int32_t f7_38 = 38 * f7; 
    int32_t f8_19 = f8 * 19; 
    int32_t f9_38 = 38 * f9; 

    int64_t f0f0    = f0 * (int64_t) f0;
    int64_t f0f1_2  = f0_2 * (int64_t) f1;
    int64_t f0f2_2  = f0_2 * (int64_t) f2;
    int64_t f0f3_2  = f0_2 * (int64_t) f3;
    int64_t f0f4_2  = f0_2 * (int64_t) f4;
    int64_t f0f5_2  = f0_2 * (int64_t) f5;
    int64_t f0f6_2  = f0_2 * (int64_t) f6;
    int64_t f0f7_2  = f0_2 * (int64_t) f7;
    int64_t f0f8_2  = f0_2 * (int64_t) f8;
    int64_t f0f9_2  = f0_2 * (int64_t) f9;
    int64_t f1f1_2  = f1_2 * (int64_t) f1;
    int64_t f1f2_2  = f1_2 * (int64_t) f2;
    int64_t f1f3_4  = f1_2 * (int64_t) f3_2;
    int64_t f1f4_2  = f1_2 * (int64_t) f4;
    int64_t f1f5_4  = f1_2 * (int64_t) f5_2;
    int64_t f1f6_2  = f1_2 * (int64_t) f6;
    int64_t f1f7_4  = f1_2 * (int64_t) f7_2;
    int64_t f1f8_2  = f1_2 * (int64_t) f8;
    int64_t f1f9_76 = f1_2 * (int64_t) f9_38;
    int64_t f2f2    = f2 * (int64_t) f2;
    int64_t f2f3_2  = f2_2 * (int64_t) f3;
    int64_t f2f4_2  = f2_2 * (int64_t) f4;
    int64_t f2f5_2  = f2_2 * (int64_t) f5;
    int64_t f2f6_2  = f2_2 * (int64_t) f6;

    int64_t carry1;
    
    carry1 = ((((f2f2 + 4 * (f0f4_2 + f1f1_2) ) * (int64_t) 32595792) + (int64_t)(1L << 24)) >> 25) 
             + (((f2f3_2 + f1f4_2 - 2 * f0f5_2) * 4) * (int64_t)65191584);

    int64_t h1 = f0f1_2 + f2f9_38 + f3f8_38 + f4f7_38 + f5f6_38;
    int64_t h2 = f0f2_2 + f1f1_2 + f3f9_76 + f4f8_38 + f5f7_76 + 19 * carry1;
    
    h[0] = (int32_t)((f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38
                - 38 * (int64_t)((( (((h2 + 19)  + (int64_type)(1L << 24) )>> 25)  + f5f5_38 * 65850 ) * (int64_t)(1L<<6) )) % ((uint64_t)1L << 26));
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
}
