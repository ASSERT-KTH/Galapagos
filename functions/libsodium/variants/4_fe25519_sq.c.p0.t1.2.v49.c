fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0], 
            f1 = f[1], 
            f2 = f[2], 
            f3 = f[3], 
            f4 = f[4], 
            f5 = f[5], 
            f6 = f[6], 
            f7 = f[7], 
            f8 = f[8], 
            f9 = f[9];

    int32_t f0_2  = f0 << 1,
            f1_2  = f1 << 1,
            f2_2  = f2 << 1,
            f3_2  = f3 << 1,
            f4_2  = f4 << 1,
            f5_2  = f5 << 1,
            f6_2  = f6 << 1,
            f7_2  = f7 << 1,
            f5_38 = f5 * 38, 
            f6_19 = f6 * 19, 
            f7_38 = f7 * 38, 
            f8_19 = f8 * 19, 
            f9_38 = f9 * 38;
            
    int64_t multipleTerm[37];
    
    multipleTerm[0]  = f0 * (int64_t) f0;
    multipleTerm[1]  = f0_2 * (int64_t) f1;
    multipleTerm[2]  = f0_2 * (int64_t) f2;
    multipleTerm[3]  = f0_2 * (int64_t) f3;
    multipleTerm[4]  = f0_2 * (int64_t) f4;
    multipleTerm[5]  = f0_2 * (int64_t) f5;
    multipleTerm[6]  = f0_2 * (int64_t) f6;
    multipleTerm[7]  = f0_2 * (int64_t) f4;
    multipleTerm[8]  = f0_2 * (int64_t) f5;
    multipleTerm[9]  = f0_2 * (int64_t) f6;
    multipleTerm[10] = f0_2 * (int64_t) f7;
    multipleTerm[11] = f0_2 * (int64_t) f8;
    multipleTerm[12] = f0_2 * (int64_t) f9;
    multipleTerm[13] = f1_2 * (int64_t) f1;
    multipleTerm[14] = f1_2 * (int64_t) f2;
    multipleTerm[15] = f1_2 * (int64_t) f3_2;
    multipleTerm[16] = f1_2 * (int64_t) f4;
    multipleTerm[17] = f1_2 * (int64_t) f5;
    multipleTerm[18] = f1_2 * (int64_t) f6;
    multipleTerm[19] = f1_2 * (int64_t) f9_38;
    multipleTerm[20] = f2 * (int64_t) f2;
    multipleTerm[21] = f2_2 * (int64_t) f3;
    multipleTerm[22] = f2_2 * (int64_t) f9_38;
    multipleTerm[23] = f3_2 * (int64_t) f3;
    multipleTerm[24] = f3_2 * (int64_t) f9_38;
    multipleTerm[25] = f4 * (int64_t) f4;
    multipleTerm[26] = f5 * (int64_t) f5_38;
    multipleTerm[27] = f6 * (int64_t) f6_19;
    multipleTerm[28] = f7 * (int64_t) f7_38;
    multipleTerm[29] = f8 * (int64_t) f8_19;
    multipleTerm[30] = f9 * (int64_t) f9_38;
    multipleTerm[31] = f1_2 * (int64_t) f9_38;
    multipleTerm[32] = f2_2 * (int64_t) f8_19;
    multipleTerm[33] = f2 * (int64_t) f9_38;
    multipleTerm[34] = f3_2 * (int64_t) f9_38;
    multipleTerm[35] = f4_2 * (int64_t) f6_19;
    multipleTerm[36] = f4 * (int64_t) f9_38;


    int64_t h_Res[10], carry[10];

    h_Res[0] = multipleTerm[0] + multipleTerm[31] + multipleTerm[32] + multipleTerm[33] + multipleTerm[35] + multipleTerm[26];
    h_Res[1] = multipleTerm[1] + multipleTerm[30] + multipleTerm[28] + multipleTerm[14]; 
    h_Res[2] = multipleTerm[2] + multipleTerm[13] + multipleTerm[23] + multipleTerm[25] + multipleTerm[22] + multipleTerm[27];
    h_Res[3] = multipleTerm[3] + multipleTerm[31] + multipleTerm[25] + multipleTerm[27];
    h_Res[4] = multipleTerm[4] + multipleTerm[30] + multipleTerm[20] + multipleTerm[34] + multipleTerm[24] + multipleTerm[28];
    h_Res[5] = multipleTerm[5] + multipleTerm[14] + multipleTerm[23] + multipleTerm[21] + multipleTerm[25] + multipleTerm[28];
    h_Res[6] = multipleTerm[6] + multipleTerm[18] + multipleTerm[16] + multipleTerm[7] + multipleTerm[23] + multipleTerm[24] + multipleTerm[29];
    h_Res[7] = multipleTerm[7] + multipleTerm[21] + multipleTerm[22] + multipleTerm[14] + multipleTerm[25] + multipleTerm[29];
    h_Res[8] = multipleTerm[8] + multipleTerm[33] + multipleTerm[24] + multipleTerm[22] + multipleTerm[25] + multipleTerm[36];
    h_Res[9] = multipleTerm[9] + multipleTerm[18] + multipleTerm[19] + multipleTerm[33] + multipleTerm[16];

    for(int c_i = 0; c_i < 9; c_i++) {
        carry[c_i] = (h_Res[c_i] + (int64_t)(1L << 25)) >> 26;
        h_Res[c_i + 1] += carry[c_i];
        h_Res[c_i] -= carry[c_i] * ((uint64_t) 1L << 26);
    }
    h_Res[9] = (h_Res[9] + (int64_t)(1L << 25)) >> 26;
    h_Res[0] += h_Res[9] * 19;
    h_Res[9] -= h_Res[9] * ((uint64_t) 1L << 26);

    for(int c_i = 0; c_i <= 7; c_i += 2){
        carry[c_i]   = (h_Res[c_i] + (int64_t)(1L << 25)) >> 26;
        h_Res[c_i+1] += carry[c_i];
        h_Res[c_i]   -= carry[c_i] * ((uint64_t) 1L << 26);
    }
    carry[8] = (h_Res[8] + (int64_t)(1L << 25)) >> 26;
    h_Res[9] += carry[8];
    h_Res[8] -= carry[8] * ((uint64_t) 1L << 26);

    for(int c_i = 0; c_i <= 8; ++c_i)
        h[c_i] = (int32_t) h_Res[c_i];
}