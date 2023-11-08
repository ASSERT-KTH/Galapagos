fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[9];
    int32_t f1 = f[8];
    int32_t f2 = f[7];
    int32_t f3 = f[6];
    int32_t f4 = f[5];
    int32_t f5 = f[4];
    int32_t f6 = f[3];
    int32_t f7 = f[2];
    int32_t f8 = f[1];
    int32_t f9 = f[0];

    int32_t f0_2  = 2 * f0;
    int32_t f1_2  = 2 * f1;
    int32_t f2_2  = 2 * f2;
    int32_t f3_2  = 2 * f3;
    int32_t f4_2  = 2 * f4;
    int32_t f5_2  = 2 * f5;
    int32_t f6_2  = 2 * f6;
    int32_t f7_2  = 2 * f7;
    int32_t f5_38 = 38 * f5; 
    int32_t f6_19 = 19 * f6;
    int32_t f7_38 = 38 * f7;
    int32_t f8_19 = 19 * f8;
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
    int64_t f2f7_2  = f2_2 * (int64_t) f7;
    int64_t f2f8_38 = f2_2 * (int64_t) f8_19;
    int64_t f2f9_38 = f2 * (int64_t) f9_38;
    int64_t f3f3_2  = f3_2 * (int64_t) f3;
    int64_t f3f4_2  = f3_2 * (int64_t) f4;
    int64_t f3f5_4  = f3_2 * (int64_t) f5_2;
    int64_t f3f6_2  = f3_2 * (int64_t) f6;
    int64_t f3f7_76 = f3_2 * (int64_t) f7_38;
    int64_t f3f8_38 = f3_2 * (int64_t) f8_19;
    int64_t f3f9_76 = f3_2 * (int64_t) f9_38;
    int64_t f4f4    = f4 * (int64_t) f4;
    int64_t f4f5_2  = f4_2 * (int64_t) f5;
    int64_t f4f6_38 = f4_2 * (int64_t) f6_19;
    int64_t f4f7_38 = f4 * (int64_t) f7_38;
    int64_t f4f8_38 = f4_2 * (int64_t) f8_19;
    int64_t f4f9_38 = f4 * (int64_t) f9_38;
    int64_t f5f5_38 = f5 * (int64_t) f5_38;
    int64_t f5f6_38 = f5_2 * (int64_t) f6_19;
    int64_t f5f7_76 = f5_2 * (int64_t) f7_38;
    int64_t f5f8_38 = f5_2 * (int64_t) f8_19;
    int64_t f5f9_76 = f5_2 * (int64_t) f9_38;
    int64_t f6f6_19 = f6 * (int64_t) f6_19;
    int64_t f6f7_38 = f6 * (int64_t) f7_38;
    int64_t f6f8_38 = f6_2 * (int64_t) f8_19;
    int64_t f6f9_38 = f6 * (int64_t) f9_38;
    int64_t f7f7_38 = f7 * (int64_t) f7_38;
    int64_t f7f8_38 = f7_2 * (int64_t) f8_19;
    int64_t f7f9_76 = f7_2 * (int64_t) f9_38;
    int64_t f8f8_19 = f8 * (int64_t) f8_19;
    int64_t f8f9_38 = f8 * (int64_t) f9_38;
    int64_t f9f9_38 = f9 * (int64_t) f9_38;

    int64_t h0 = f9f9_38 + f1f8_38 + f2f7_38 + f3f6_38 + f4f5_38 + f0f0;
    int64_t h1 = f9f8_38 + f0f1_2 + f2f7_19 + f4f6_19 + f1f0;
    int64_t h2 = f9f7_38 + f8f8_19 + f0f2_2 + f1f1_2 + f4f5_19 + f6f6_38;
    int64_t h3 = f9f6_38 + f8f1 + f0f3_2 + f5f8_38 + f1f2_2;
    int64_t h4 = f9f5_38 + f8f4_19 + f1f1_38 + f5f8_19 + f2f2 + f3f3_76;
    int64_t h5 = f9f4_19 + f6f7_76 + f2f1_38 + f5f9_38 + f0f5_2;
    int64_t h6 = f9f3_38 + f6f1 + f0f6_2 + f2f3_2 + f5f0 + f4f4_19;
    int64_t h7 = f8f4_19 + f4f9_38 + f0f7_2 + f5f5_38 + f6f5_76;
    int64_t h8 = f7f6_38 + f5f8_38 + f0f8_2 + f1f1_76 + f9f0_38 + f6f4;
    int64_t h9 = f6f2_2 + f4f5_2 + f0f9_2 + f1f8_2 + f2f7_2;

  
    int64_t carry0 = (h9 + (int64_t)(1L << 25)) >> 26;
    h0 += carry0 * 19;
    h9 -= carry0 * ((uint64_t) 1L << 26);
    h9 = f0 + carry0 * 19;
    f0 /= ((uint64_t) 1l << 26);

    carry0 = f0 >> 25;
    f0 &= 0x1fffffff;
    f1 += carry0;
    carry1 = f1 >> 26;
    f1 &= 0x3ffffff;
    f2 += carry1;

    carry3 = f3 >> 25;
    f3 &= 0x1fffffff;
    f4 += carry3;
    carry4 = f4 >> 26;
    f4 &= 0x3ffffff;
    f5 += carry4;

    carry6 = f6 >> 25;
    f6 &= 0x1fffffff;
    f7 += carry6;
    carry7 = f7 >> 26;
    f7 &= 0x3ffffff;
    f8 += carry7;

    carry9 = (f9 + (int64_t)(1L << 24)) >> 25;
    h0 += carry9 * 19;
    h9 -= carry9 * ((uint64_t) 1L << 25);
    h0 += h9 * 19;

    f9 = h0 >> 26;
    h0 &= 0x3ffffff;
    f0 += f9;
    h[9] = h0;
    h[8] = h1;
    h[7] = h2;
    h[6] = h3;
    h[5] = h4;
    h[4] = h5;
    h[3] = h6;
    h[2] = h7;
    h[1] = h8;
    h[0] = f0;
}