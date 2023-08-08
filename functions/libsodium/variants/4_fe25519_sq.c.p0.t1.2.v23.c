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

    int32_t f0_2  = f0 << 1;
    int32_t f1_2  = f1 << 1;
    int32_t f2_2  = f2 << 1;
    int32_t f3_2  = f3 << 1;
    int32_t f4_2  = f4 << 1;
    int32_t f5_2  = f5 << 1;
    int32_t f6_2  = f6 << 1;
    int32_t f7_2  = f7 << 1;
    int32_t f5_38 = 38 * f5;
    int32_t f6_19 = 19 * f6;
    int32_t f7_38 = 38 * f7;
    int32_t f8_19 = 19 * f8;
    int32_t f9_38 = 38 * f9;  

    int64_t f0f0    = (int64_t) f0 * f0;
    int64_t f0f1_2  = (int64_t) f0_2 * f1;
    int64_t f1f1_2  = (int64_t) f1_2 * f1;
    int64_t f1f2_2  = (int64_t) f1_2 * f2;
    
    int64_t carry0;
    int64_t carry9;
    
    int64_t h0 = f0f0 + f1f1_2 + f1f2_2;
    
    carry0 = (h0 + (int64_t)(1 << 25)) >> 26;
    h0 -= carry0 * ((uint64_t) 1L << 26);
    
    carry9 = (h0 + (int64_t)(1 << 24)) >> 25;
    h0 += carry9 * 19;
    h0 -= carry9 * ((uint64_t) 1L << 25);
    
    h[0] = (int32_t) h0;
    
    for (int i = 1; i < 10; ++i) {
        int64_t h_val = f0 * (int64_t)f[i];
        int64_t carry_val = (h_val + (int64_t)(1 << 26)) >> 27;
        h_val -= carry_val * ((uint64_t) 1L << 27);
        carry9 = (h_val + (int64_t)(1 << 25)) >> 25;
        h_val += carry9 * 19;
        h_val -= carry9 * ((uint64_t) 1L << 25);
        h[i] = (int32_t) h_val;
    }
}