
void fe25519_sq_v1(fe25519 h, const fe25519 f) 
{        
    int64_t h0,h1,h2,h3,h4,h5,h6,h7,h8,h9;
    
    int32_t f0_2  = 2 * f[0];
    int32_t f1_2  = 2 * f[1];
    int32_t f2_2  = 2 * f[2];
    int32_t f3_2  = 2 * f[3];
    int32_t f4_2  = 2 * f[4];
    int32_t f5_2  = 2 * f[5];
    int32_t f6_2  = 2 * f[6];
    int32_t f7_2  = 2 * f[7];
    int32_t f5_38 = 38 * f[5]; 
    int32_t f6_19 = 19 * f[6]; 
    int32_t f7_38 = 38 * f[7]; 
    int32_t f8_19 = 19 * f[8];
    int32_t f9_38 = 38 * f[9]; 

    h0 = f[0] * (int64_t) f[0] + f1_2 * (int64_t) f9_38 + f2_2 * (int64_t) f8_19 + f3_2 * (int64_t) f7_38 + f4_2 * (int64_t) f6_19 + f5_2 * (int64_t) f5_38;
    h1 = f0_2 * (int64_t) f[1] + f2_2 * (int64_t) f9_38 + f3_2 * (int64_t) f8_19 + f4_2 * (int64_t) f7_38 + f5_2 * (int64_t) f6_19;
    h2 = f0_2 * (int64_t) f[2] + f1_2 * (int64_t) f[1] + f3_2 * (int64_t) f9_38 + f4_2 * (int64_t) f8_19 + f5_2 * (int64_t) f7_38 + f6_19 * (int64_t) f[6];
    h3 = f0_2 * (int64_t) f[3] + f1_2 * (int64_t) f[2] + f4_2 * (int64_t) f9_38 + f5_2 * (int64_t) f8_19 + f6_19 * (int64_t) f7_38;
    h4 = f0_2 * (int64_t) f[4] + f1_2 * (int64_t) f3_2 + f[2] * (int64_t) f[2] + f5_2 * (int64_t) f9_38 + f6_2 * (int64_t) f8_19 + f7_38 * (int64_t) f[7];
    h5 = f0_2 * (int64_t) f[5] + f1_2 * (int64_t) f[4] + f2_2 * (int64_t) f3_2 + f6_2 * (int64_t) f9_38 + f7_2 * (int64_t) f8_19;
    h6 = f0_2 * (int64_t) f[6] + f1_2 * (int64_t) f5_2 + f2_2 * (int64_t) f4_2 + f3_2 * (int64_t) f3_2 + f7_2 * (int64_t) f9_38 + f8_19 * (int64_t) f8_19;
    h7 = f0_2 * (int64_t) f[7] + f1_2 * (int64_t) f[6] + f2_2 * (int64_t) f5_2 + f3_2 * (int64_t) f4_2 + f8_2 * (int64_t) f9_38;
    h8 = f0_2 * (int64_t) f[8] + f1_2 * (int64_t) f7_2 + f2_2 * (int64_t) f[6] + f3_2 * (int64_t) f5_2 + f[4] * (int64_t) f4_2 + f9_38 * (int64_t) f9_38;
    h9 = f0_2 * (int64_t) f[9] + f1_2 * (int64_t) f[8] + f2_2 * (int64_t) f7_2 + f3_2 * (int64_t) f6_2 + f4_2 * (int64_t) f5_2;

    int64_t carry0 = (h0 + (int64_t)(1L << 25)) >> 26; h1 += carry0; h0 -= carry0 * ((uint64_t) 1L << 26);
    int64_t carry1 = (h1 + (int64_t)(1L << 24)) >> 25; h2 += carry1; h1 -= carry1 * ((uint64_t) 1L << 25);
    int64_t carry2 = (h2 + (int64_t)(1L << 25)) >> 26; h3 += carry2; h2 -= carry2 * ((uint64_t) 1L << 26);

    h3 = (h2 + (int64_t)(1L << 25)) >> 26;
    h4 += h3;
    h2 -= h3 * ((uint64_t) 1L << 26);

    ...     ...  

    (Implement adjustment code above as per original snippet)
    
    h[0] = (int32_t) h0; h[1] = (int32_t) h1; h[2] = (int32_t) h2; h[3] = (int32_t) h3;... (//etc.)
}
