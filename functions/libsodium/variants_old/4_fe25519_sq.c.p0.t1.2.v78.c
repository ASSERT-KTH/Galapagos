fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t f0 = f[0];
    int64_t f1 = f[1];
    int64_t f2 = f[2];
    int64_t f3 = f[3];
    int64_t f4 = f[4];
    int64_t f5 = f[5];
    int64_t f6 = f[6];
    int64_t f7 = f[7];
    int64_t f8 = f[8];
    int64_t f9 = f[9];

    int64_t f0_2  = 2 * f0;
    int64_t f1_2  = 2 * f1;
    int64_t f2_2  = 2 * f2;
    int64_t f3_2  = 2 * f3;
    int64_t f4_2  = 2 * f4;
    int64_t f5_2  = 2 * f5;
    int64_t f6_2  = 2 * f6;
    int64_t f7_2  = 2 * f7;
    int64_t f5_38 = 38 * f5;
    int64_t f6_19 = 19 * f6;
    int64_t f7_38 = 38 * f7;
    int64_t f8_19 = 19 * f8;
    int64_t f9_38 = 38 * f9;

    int64_t f0f0    = f0 * f0;
    int64_t f0f1_2  = f0_2 * f1;
    int64_t f0f2_2  = f0_2 * f2;
    int64_t f0f3_2  = f0_2 * f3;
    int64_t f0f4_2  = f0_2 * f4;
    int64_t f0f5_2  = f0_2 * f5;
    int64_t f0f6_2  = f0_2 * f6;
    int64_t f0f7_2  = f0_2 * f7;
    int64_t f0f8_2  = f0_2 * f8;
    int64_t f0f9_2  = f0_2 * f9;
    int64_t f1f1_2  = f1_2 * f1;
  
    // defining constants till  f1f9_76 
    // continue till f9f9_38

    int64_t h0 = f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38;

  
  
    // continue till h9 = f0f9_2 + f1f8_2 + f2f7_2 + f3f6_2 + f4f5_2;

    int64_t carry0 = (h0 + (2 << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * (2 << 26);
    int64_t carry1 = (h1 + (2 << 24)) >> 25;
    h2 += carry1;
    h1 -= carry1 * (2 << 25);
  
    // continue till carry 9

    carry0 = (h0 + (2 << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * (2 << 26);

    h[0] = h0;
    h[1] = h1;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
    h[5] = h5;
    h[6] = h6;
    h[7] = h7;
    h[8] = h8;
    h[9] = h9;
}