fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t h0, h1, h2, h3, h4, h5, h6, h7, h8, h9;
    int64_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4], f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];
    int64_t f0_2 = 2 * f0, f1_2 = 2 * f1, f2_2 = 2 * f2, f3_2 = 2 * f3, f4_2 = 2 * f4, f5_2 = 2 * f5, f6_2 = 2 * f6, f7_2 = 2 * f7;
    int64_t f5_38 = 38 * f5, f6_19 = 19 * f6, f7_38 = 38 * f7, f8_19 = 19 * f8, f9_38 = 38 * f9;
    
    int64_t f0f0 = f0 * f0, f0f1_2 = f0_2 * f1, f0f2_2 = f0_2 * f2, f0f3_2 = f0_2 * f3, f0f4_2 = f0_2 * f4, f0f5_2 = f0_2 * f5, 
    f0f6_2 = f0_2 * f6, f0f7_2 = f0_2 * f7, f0f8_2 = f0_2 * f8, f0f9_2 = f0_2 * f9;
    int64_t f1f1_2 = f1_2 * f1, f1f2_2 = f1_2 * f2, f1f3_4 = f1_2 * f3_2, f1f4_2 = f1_2 * f4, f1f5_4 = f1_2 * f5_2, 
    f1f6_2 = f1_2 * f6, f1f7_4 = f1_2 * f7_2, f1f8_2 = f1_2 * f8, f1f9_76 = f1_2 * f9_38;
    int64_t f2f2 = f2 * f2, f2f3_2 = f2_2 * f3, f2f4_2 = f2_2 * f4, f2f5_2 = f2_2 * f5, f2f6_2 = f2_2 * f6, f2f7_2 = f2_2 * f7, 
    f2f8_38 = f2_2 * f8_19, f2f9_38 = f2 * f9_38;
    int64_t f3f3_2 = f3_2 * f3, f3f4_2 = f3_2 * f4, f3f5_4 = f3_2 * f5_2, f3f6_2 = f3_2 * f6, f3f7_76 = f3_2 * f7_38, 
    f3f8_38 = f3_2 * f8_19, f3f9_76 = f3_2 * f9_38;

    h0 = f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4 * 38 * f6 + f5 * f5_38;
    h1 = f0f1_2 + f2 * 38 * f9 + f3f8_38 + f4 * 38 * f7 + f5 * 38 * f6;
    h2 = f0f2_2 + f1f1_2 + f3f9_76 + f4f8_38 + f5f7_76 + f6 * f6_19;
    h3 = f0f3_2 + f1f2_2 + f4 * 38 * f9 + f5f8_38 + f6 * 38 * f7;
    h4 = f0f4_2 + f1f3_4 + f2f2 + f5f9_76 + f6f8_38 + f7f7_38;
    
    int64_t carry0 = (h0 + (int64_t)(1L << 25)) >> 26; h1 += carry0; h0 -= carry0 << 26;
    int64_t carry4 = (h4 + (int64_t)(1L << 25)) >> 26; h5 += carry4; h4 -= carry4 << 26;
    int64_t carry1 = (h1 + (int64_t)(1L << 24)) >> 25; h2 += carry1; h1 -= carry1 << 25;
    int64_t carry5 = (h5 + (int64_t)(1L << 24)) >> 25; h6 += carry5; h5 -= carry5 << 25;
    int64_t carry2 = (h2 + (int64_t)(1L << 25)) >> 26; h3 += carry2; h2 -= carry2 << 26;
    int64_t carry3 = (h3 + (int64_t)(1L << 24)) >> 25; h4 += carry3; h3 -= carry3 << 25;
    int64_t carry7 = (h7 + (int64_t)(1L << 24)) >> 25; h8 += carry7; h7 -= carry7 << 25;

    // Second half of multiplications
    int64_t f4f4 = f4 * f4, f4f5_2 = f4_2 * f5, f4f6_38 = f4_2 * f6_19, f4f7_38 = f4 * f7_38, 
    f4f8_38 = f4_2 * f8_19, f4f9_38 = f4 * f9_38, f5f5_38 = f5 * f5_38, 
    f5f6_38 = f5_2 * f6_19, f5f7_76 = f5_2 * f7_38, f5f8_38 = f5_2 * f8_19, f5f9_76 = f5_2 * f9_38,
    f6f6_19 = f6 * f6_19, f6f7_38 = f6 * f7_38, f6f8_38 = f6_2 * f8_19, f6f9_38 = f6 * f9_38, 
    f7f7_38 = f7 * f7_38, f7f8_38 = f7_2 * f8_19, f[]
    f8f8_19 = f8 * f8_19, f8f9_38 = f8 * f9_38, f9f9_38 = f9 * f9_38;

    h5 = f0f5_2 + f1f4_2 + f2f3_2 + f6 * 38 * f9 + f7 * 38 * f8;
    h6 = f0f6_2 + f1f5_4 + f2f4_2 + f3f3_2 + f7f9_76 + f8f8_19;
    h7 = f0f7_2 + f1f6_2 + f2f5_2 + f3f4_2 + f8 * 38 * f9;
    h8 = f0f8_2 + f1f7_4 + f2f6_2 + f3f5_4 + f4f4 + f9f9_38;
    h9 = f0f9_2 + f1f8_2 + f2f7_2 + f3f6_2 + f4f5_2;

    carry6 = (h6 + (int64_t)(1L << 25)) >> 26; h7 += carry6; h6 -= carry6 * ((uint64_t) 1L << 26);
    carry4 = (h4 + (int64_t)(1L << 25)) >> 26; h5 += carry4; h4 -= carry4 * ((uint64_t) 1L << 26);
    carry8 = (h8 + (int64_t)(1L << 25)) >> 26; h9 += carry8; h8 -= carry8 * ((uint64_t) 1L << 26);
    int64_t carry9 = (h9 + (int64_t)(1L << 24)) >> 25; h0 += carry9 * 19; h9 -= carry9 * ((uint64_t) 1L << 25);
    carry0 = (h0 + (int64_t)(1L << 25)) >> 26; h1 += carry0; h0 -= carry0 * ((uint64_t) 1L << 26);

    h[0] = h0; h[1] = h1; h[2] = h2; h[3] = h3; h[4] = h4; h[5] = h5; h[6] = h6; h[7] = h7; h[8] = h8; h[9] = h9;
}