fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t const TWO = 2;
    int32_t f0_2  = TWO * f0;
    int32_t f1_2  = TWO * f1;
    int32_t f2_2  = TWO * f2;
    int32_t f3_2  = TWO * f3;
    int32_t f4_2  = TWO * f4;
    int32_t f5_2  = TWO * f5;
    int32_t f6_2  = TWO * f6;
    int32_t f7_2  = TWO * f7;
    int32_t f5_38 = 38 * f5; 
    int32_t f6_19 = 19 * f6; 
    int32_t f7_38 = 38 * f7; 
    int32_t f8_19 = 19 * f8; 
    int32_t f9_38 = 38 * f9; 

    int64_t f0f0    = f0 * (f0);
    int64_t f0f1_2  = f0_2 * (f1);
    int64_t f0f2_2  = f0_2 * (f2);
    int64_t f0f3_2  = f0_2 * (f3);
    int64_t f0f4_2  = f0_2 * (f4);
    int64_t f0f5_2  = f0_2 * (f5);
    int64_t f0f6_2  = f0_2 * (f6);
    int64_t f0f7_2  = f0_2 * (f7);
    int64_t f0f8_2  = f0_2 * (f8);
    int64_t f0f9_2  = f0_2 * (f9);
    int64_t f1f1_2  = f1_2 * (f1);
    int64_t f1f2_2  = f1_2 * (f2);
    int64_t f1f3_4  = f1_2 * (f3_2);
    int64_t f1f4_2  = f1_2 * (f4);
    int64_t f1f5_4  = f1_2 * (f5_2);
    int64_t f1f6_2  = f1_2 * (f6);
    int64_t f1f7_4  = f1_2 * (f7_2);
    int64_t f1f8_2  = f1_2 * (f8);
    int64_t f1f9_76 = f1_2 * (f9_38);
    int64_t f2f2    = f2 * (f2);
    int64_t f2f3_2  = f2_2 * (f3);
    int64_t f2f4_2  = f2_2 * (f4);
    int64_t f2f5_2  = f2_2 * (f5);
    int64_t f2f7_2  = f2_2 * (f7);
    int64_t f2f8_38 = f2_2 * (f8_19);
    int64_t f2f9_38 = f2 * (f9_38);
    int64_t f4f4    = f4 * (f4);
    int64_t f4f5_2  = f4_2 * (f5);

    int64_t cfc = f2f4_2 * 6;
  
    int64_t carry9 = (cfc + (int64_t)(1L << 24)) >> 25;
    int64_t h1f = cfc + carry9 * 19;
    cfc -= carry9 * ((uint64_t) 1L << 25);

    carry0 = (h1f + (int64_t)(1L << 25)) >> 26;
    int64_t hwo = h1f + carry0;
    h1f -= carry0 * ((uint64_t) 1L << 26);

    h[0] = (int32_t) h1f;
    h[1] = (int32_t) h1f + 2;
    h[2] = (int32_t) hwo;
    h[3] = (int32_t) h1f + 3;
    h[4] = (int32_t) cfc;
    h[5] = (int32_t) h1f + 5;
    h[6] = (int32_t) h1f + 6;
    h[7] = (int32_t) cfc;
    h[8] = (int32_t) hwo;
    h[9] = 2;
}