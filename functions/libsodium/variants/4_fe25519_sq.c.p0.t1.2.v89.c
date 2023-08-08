fe25519_sq(fe25519 h, const fe25519 f)
{
    uint32_t f0 = f[0];
    uint32_t f1 = f[1];
    uint32_t f2 = f[2];
    uint32_t f3 = f[3];
    uint32_t f4 = f[4];
    uint32_t f5 = f[5];
    uint32_t f6 = f[6];
    uint32_t f7 = f[7];
    uint32_t f8 = f[8];
    uint32_t f9 = f[9];

    uint32_t f0_2  = 2 * f0;
    uint32_t f1_2  = 2 * f1;
    uint32_t f2_2  = 2 * f2;
    uint32_t f3_2  = 2 * f3;
    uint32_t f4_2  = 2 * f4;
    uint32_t f5_2  = 2 * f5;
    uint32_t f6_2  = 2 * f6;
    uint32_t f7_2  = 2 * f7;
    uint32_t f5_38 = 38 * f5; 
    uint32_t f6_19 = 19 * f6; 
    uint32_t f7_38 = 38 * f7; 
    uint32_t f8_19 = 19 * f8;
    uint32_t f9_38 = 38 * f9;

    uint64_t f0f0    = f0 * (uint64_t) f0;
    uint64_t f0f1_2  = f0_2 * (uint64_t) f1;
    uint64_t f0f2_2  = f0_2 * (uint64_t) f2;
    uint64_t f0f3_2  = f0_2 * (uint64_t) f3;
    uint64_t f0f4_2  = f0_2 * (uint64_t) f4;
    uint64_t f0f5_2  = f0_2 * (uint64_t) f5;
    uint64_t f0f6_2  = f0_2 * (uint64_t) f6;
    uint64_t f0f7_2  = f0_2 * (uint64_t) f7;
    uint64_t f0f8_2  = f0_2 * (uint64_t) f8;
    uint64_t f0f9_2  = f0_2 * (uint64_t) f9;
    uint64_t f1f1_2  = f1_2 * (uint64_t) f1;
    uint64_t f1f2_2  = f1_2 * (uint64_t) f2;
    uint64_t f1f3_4  = f1_2 * (uint64_t) f3_2;
    uint64_t f1f4_2  = f1_2 * (uint64_t) f4;
    uint64_t f1f5_4  = f1_2 * (uint64_t) f5_2;
    uint64_t f1f6_2  = f1_2 * (uint64_t) f6;
    uint64_t f1f7_4  = f1_2 * (uint64_t) f7_2;
    uint64_t f1f8_2  = f1_2 * (uint64_t) f8;
    uint64_t f1f9_76 = f1_2 * (uint64_t) f9_38;
    uint64_t f2f2    = f2 * (uint64_t) f2;
    uint64_t f2f3_2  = f2_2 * (uint64_t) f3;
    uint64_t f2f4_2  = f2_2 * (uint64_t) f4;
    uint64_t f2f5_2  = f2_2 * (uint64_t) f5;
    uint64_t f2f6_2  = f2_2 * (uint64_t) f6;
    uint64_t f2f7_2  = f2_2 * (uint64_t) f7;
    uint64_t f2f8_38 = f2_2 * (uint64_t) f8_19;
    uint64_t f2f9_38 = f2 * (uint64_t) f9_38;
    uint64_t f3f3_2  = f3_2 * (uint64_t) f3;
    uint64_t f3f4_2  = f3_2 * (uint64_t) f4;
    uint64_t f3f5_4  = f3_2 * (uint64_t) f5_2;
    uint64_t f3f6_2  = f3_2 * (uint64_t) f6;
    uint64_t f3f7_76 = f3_2 * (uint64_t) f7_38;
    uint64_t f3f8_38 = f3_2 * (uint64_t) f8_19;
    uint64_t f3f9_76 = f3_2 * (uint64_t) f9_38;
   
    uint64_t h0 = f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38;
    uint64_t h1 = f0f1_2 + f2f9_38 + f3f8_38 + f4f7_38 + f5f6_38;
    uint64_t h2 = f0f2_2 + f1f1_2 + f3f9_76 + f4f8_38 + f5f7_76 + f6f6_19;
    uint64_t h3 = f0f3_2 + f1f2_2 + f4f9_38 + f5f8_38 + f6f7_38;
    uint64_t h4 = f0f4_2 + f1f3_4 + f2f2 + f5f9_76 + f6f8_38 + f7f7_38;
    uint64_t h5 = f0f5_2 + f1f4_2 + f2f3_2 + f6f9_38 + f7f8_38;
    uint64_t h6 = f0f6_2 + f1f5_4 + f2f4_2 + f3f3_2 + f7f9_76 + f8f8_19;
    uint64_t h7 = f0f7_2 + f1f6_2 + f2f5_2 + f3f4_2 + f8f9_38;
    uint64_t h8 = f0f8_2 + f1f7_4 + f2f6_2 + f3f5_4 + f4f4 + f9f9_38;
    uint64_t h9 = f0f9_2 + f1f8_2 + f2f7_2 + f3f6_2 + f4f5_2;

    uint64_t carry0;
    uint64_t carry1;
    uint64_t carry2;
    uint64_t carry3;
    uint64_t carry4;
    uint64_t carry5;
    uint64_t carry6;
    uint64_t carry7;
    uint64_t carry8;
    uint64_t carry9;

    carry0 = (h0 + (uint64_t)(1UL << 25)) >> 26;
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1UL << 26);
    carry4 = (h4 + (uint64_t)(1UL << 25)) >> 26; 
    h5 += carry4;
    h4 -= carry4 * ((uint64_t) 1UL << 26);

    carry1 = (h1 + (uint64_t)(1UL << 24)) >> 25;
    h2 += carry1;
    h1 -= carry1 * ((uint64_t) 1UL << 25);
    carry5 = (h5 + (uint64_t)(1UL << 24)) >> 25;
    h6 += carry5;
    h5 -= carry5 * ((uint64_t) 1UL << 25);

    carry2 = (h2 + (uint64_t)(1UL << 25)) >> 26; 
    h3 += carry2;
    h2 -= carry2 * ((uint64_t) 1UL << 26);
    carry6 = (h6 + (uint64_t)(1UL << 25)) >> 26;
    h7 += carry6;
    h6 -= carry6 * ((uint64_t) 1UL << 26);

    carry3 = (h3 + (uint64_t)(1UL << 24)) >> 25; 
    h4 += carry3;
    h3 -= carry3 * ((uint64_t) 1UL << 25);
    carry7 = (h7 + (uint64_t)(1UL << 24)) >> 25; 
    h8 += carry7;
    h7 -= carry7 * ((uint64_t) 1UL << 25);

    carry4 = (h4 + (uint64_t)(1UL << 25)) >> 26;
    h5 += carry4;
    h4 -= carry4 * ((uint64_t) 1UL << 26);  
    carry8 = (h8 + (uint64_t)(1UL << 25)) >> 26;
    h9 += carry8;
    h8 -= carry8 * ((uint64_t) 1UL << 26);

    carry9 = (h9 + (uint64_t)(1UL << 24)) >> 25;
    h0 += carry9 * 19;
    h9 -= carry9 * ((uint64_t) 1UL << 25);

    carry0 = (h0 + (uint64_t)(1UL << 25)) >> 26; 
    h1 += carry0;
    h0 -= carry0 * ((uint64_t) 1UL << 26);

    h[0] = (uint32_t) h0;
    h[1] = (uint32_t) h1;
    h[2] = (uint32_t) h2;
    h[3] = (uint32_t) h3;
    h[4] = (uint32_t) h4;
    h[5] = (uint32_t) h5;
    h[6] = (uint32_t) h6;
    h[7] = (uint32_t) h7;
    h[8] = (uint32_t) h8;
    h[9] = (uint32_t) h9;
}