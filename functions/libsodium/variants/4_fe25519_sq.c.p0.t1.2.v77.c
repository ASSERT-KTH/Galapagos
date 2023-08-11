void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t temp_f[10];

    for(int i=0; i<10; i++){
        temp_f[i] = f[i];
    }

    int32_t f0_2  = 2 * temp_f[0];
    int32_t f1_2  = 2 * temp_f[1];
    int32_t f2_2  = 2 * temp_f[2];
    int32_t f3_2  = 2 * temp_f[3];
    int32_t f4_2  = 2 * temp_f[4];
    int32_t f5_2  = 2 * temp_f[5];
    int32_t f6_2  = 2 * temp_f[6];
    int32_t f7_2  = 2 * temp_f[7];
    int32_t f5_38 = 38 * temp_f[5]; 
    int32_t f6_19 = 19 * temp_f[6]; 
    int32_t f7_38 = 38 * temp_f[7]; 
    int32_t f8_19 = 19 * temp_f[8]; 
    int32_t f9_38 = 38 * temp_f[9]; 

    int64_t f0f0    = temp_f[0] * (int64_t) temp_f[0];
    int64_t f0f1_2  = f0_2 * (int64_t) temp_f[1];
    int64_t f0f2_2  = f0_2 * (int64_t) temp_f[2];
    int64_t f0f3_2  = f0_2 * (int64_t) temp_f[3];
    int64_t f0f4_2  = f0_2 * (int64_t) temp_f[4];
    int64_t f0f5_2  = f0_2 * (int64_t) temp_f[5];
    int64_t f0f6_2  = f0_2 * (int64_t) temp_f[6];
    int64_t f0f7_2  = f0_2 * (int64_t) temp_f[7];
    int64_t f0f8_2  = f0_2 * (int64_t) temp_f[8];
    int64_t f0f9_2  = f0_2 * (int64_t) temp_f[9];
    int64_t f1f1_2  = f1_2 * (int64_t) temp_f[1];
    int64_t f1f2_2  = f1_2 * (int64_t) temp_f[2];
    int64_t f1f3_4  = f1_2 * (int64_t) f3_2;
    int64_t f1f4_2  = f1_2 * (int64_t) temp_f[4];
    int64_t f1f5_4  = f1_2 * (int64_t) f5_2;
    int64_t f1f6_2  = f1_2 * (int64_t) temp_f[6];
    int64_t f1f7_4  = f1_2 * (int64_t) f7_2;
    int64_t f1f8_2  = f1_2 * (int64_t) temp_f[8];
    int64_t f1f9_76 = f1_2 * (int64_t) f9_38;
    int64_t f2f2    = temp_f[2] * (int64_t) temp_f[2];
    int64_t f2f3_2  = f2_2 * (int64_t) temp_f[3];
    int64_t f2f4_2  = f2_2 * (int64_t) temp_f[4];
    int64_t f2f5_2  = f2_2 * (int64_t) temp_f[5];
    int64_t f2f6_2  = f2_2 * (int64_t) temp_f[6];
    int64_t f2f7_2  = f2_2 * (int64_t) temp_f[7];
    int64_t f2f8_38 = f2_2 * (int64_t) f8_19;
    int64_t f2f9_38 = temp_f[2] * (int64_t) f9_38;
    int64_t f3f3_2  = f3_2 * (int64_t) temp_f[3];
    int64_t f3f4_2  = f3_2 * (int64_t) temp_f[4];
    int64_t f3f5_4  = f3_2 * (int64_t) f5_2;
    int64_t f3f6_2  = f3_2 * (int64_t) temp_f[6];
    int64_t f3f7_76 = f3_2 * (int64_t) f7_38;
    int64_t f3f8_38 = f3_2 * (int64_t) f8_19;
    int64_t f3f9_76 = f3_2 * (int64_t) f9_38;
    int64_t f4f4    = temp_f[4] * (int64_t) temp_f[4];
    int64_t f4f5_2  = f4_2 * (int64_t) temp_f[5];
    int64_t f4f6_38 = f4_2 * (int64_t) f6_19;
    int64_t f4f7_38 = temp_f[4] * (int64_t) f7_38;
    int64_t f4f8_38 = f4_2 * (int64_t) f8_19;
    int64_t f4f9_38 = temp_f[4] * (int64_t) f9_38;
    int64_t f5f5_38 = temp_f[5] * (int64_t) f5_38;
    int64_t f5f6_38 = f5_2 * (int64_t) f6_19;
    int64_t f5f7_76 = f5_2 * (int64_t) f7_38;
    int64_t f5f8_38 = f5_2 * (int64_t) f8_19;
    int64_t f5f9_76 = f5_2 * (int64_t) f9_38;
    int64_t f6f6_19 = temp_f[6] * (int64_t) f6_19;
    int64_t f6f7_38 = temp_f[6] * (int64_t) f7_38;
    int64_t f6f8_38 = f6_2 * (int64_t) f8_19;
    int64_t f6f9_38 = temp_f[6] * (int64_t) f9_38;
    int64_t f7f7_38 = temp_f[7] * (int64_t) f7_38;
    int64_t f7f8_38 = f7_2 * (int64_t) f8_19;
    int64_t f7f9_76 = f7_2 * (int64_t) f9_38;
    int64_t f8f8_19 = temp_f[8] * (int64_t) f8_19;
    int64_t f8f9_38 = temp_f[8] * (int64_t) f9_38;
    int64_t f9f9_38 = temp_f[9] * (int64_t) f9_38;

    int64_t h0 = f0f0 + f1f9_76 + f2f8_38 + f3f7_76 + f4f6_38 + f5f5_38;
    int64_t h1 = f0f1_2 + f2f9_38 + f3f8_38 + f4f7_38 + f5f6_38;
    int64_t h2 = f0f2_2 + f1f1_2 + f3f9_76 + f4f8_38 + f5f7_76 + f6f6_19;
    int64_t h3 = f0f3_2 + f1f2_2 + f4f9_38 + f5f8_38 + f6f7_38;
    int64_t h4 = f0f4_2 + f1f3_4 + f2f2 + f5f9_76 + f6f8_38 + f7f7_38;
    int64_t h5 = f0f5_2 + f1f4_2 + f2f3_2 + f6f9_38 + f7f8_38;
    int64_t h6 = f0f6_2 + f1f5_4 + f2f4_2 + f3f3_2 + f7f9_76 + f8f8_19;
    int64_t h7 = f0f7_2 + f1f6_2 + f2f5_2 + f3f4_2 + f8f9_38;
    int64_t h8 = f0f8_2 + f1f7_4 + f2f6_2 + f3f5_4 + f4f4 + f9f9_38;
    int64_t h9 = f0f9_2 + f1f8_2 + f2f7_2 + f3f6_2 + f4f5_2;

    carry_operations(h, h0, h1, h2, h3, h4, h5, h6, h7, h8, h9);
}
