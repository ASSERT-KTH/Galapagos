fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_new[10], g_new[10];
    for(int i=0; i<10; i++){
       f_new[i] = f[i];
       g_new[i] = g[i];
    }
    
    int32_t g1_19 = 19 * g_new[1];
    int32_t g2_19 = 19 * g_new[2];
    int32_t g3_19 = 19 * g_new[3];
    int32_t g4_19 = 19 * g_new[4];
    int32_t g5_19 = 19 * g_new[5];
    int32_t g6_19 = 19 * g_new[6];
    int32_t g7_19 = 19 * g_new[7];
    int32_t g8_19 = 19 * g_new[8];
    int32_t g9_19 = 19 * g_new[9];
    
    int32_t f1_2  = 2 * f_new[1];
    int32_t f3_2  = 2 * f_new[3];
    int32_t f5_2  = 2 * f_new[5];
    int32_t f7_2  = 2 * f_new[7];
    int32_t f9_2  = 2 * f_new[9];

    int64_t product_results[100];

    for(int i=0; i<10; i++){
         for(int j=0; j<10; j++){
            product_results[i*10 + j] = f_new[i] * (int64_t) g_new[j];
         }
    }
    
    int64_t h_values[10];

    h_values[0] = product_results[0] + product_results[19] + product_results[28] + product_results[37] + product_results[46] + product_results[65] +
                 product_results[54] + product_results[43] + product_results[38] + product_results[11];
    h_values[1] = product_results[1] + product_results[10] + product_results[29] + product_results[38] + product_results[47] + product_results[56] + product_results[64] +
                 product_results[53] + product_results[44] + product_results[12];
    h_values[2] = product_results[2] + f_new[1] * 2 * (int64_t) g_new[1] + product_results[20] + product_results[57] + product_results[36] + product_results[67] + product_results[46] +
                 f_new[7] * 2 * (int64_t) g_new[5] + product_results[48] + 2 * (int64_t) g_new[3] * f_new[9];
    h_values[3] = product_results[3] + product_results[12] + product_results[21] + product_results[30] + product_results[37] + product_results[58] + product_results[47] + 
                 product_results[44] + product_results[65] + g_new[4] * f_new[9];
    h_values[4] = f_new[0] * g_new[4] + 2 * (int64_t) g_new[1] * f_new[3] + product_results[22] + product_results[31] + product_results[40] + f_new[9]*2*(int64_t)g_new[2] + product_results[48]+f_new[7]*2*(int64_t) g_new[7]+f_new[8]*2*(int64_t)g_new[6] + f_new[9]*2*(int64_t)g_new[5];
    h_values[5] = f_new[0] * g_new[5] + product_results[13] + product_results[23] + product_results[32] + product_results[41] + f_new[5] * (int64_t) g_new[0] + g_new[6]*f_new[2] + g_new[7]*(int64_t)f_new[1]*2 + 
                 g_new[8]*(int64_t)f_new[2] + g_new[9]*(int64_t)f_new[1];
    h_values[6] = f_new[0] * g_new[6] + 2 * (int64_t) g_new[1] * f_new[5] + product_results[24] + 2 * (int64_t) g_new[3] * f_new[3] + product_results[42] + f_new[5] * 2 * (int64_t) g_new[1] + product_results[60] +
                 f_new[9]*g_new[3]*76 + product_results[49] + f_new[7]*2*(int64_t) g_new[9];
    h_values[7] = f_new[0] * g_new[7] + product_results[15] + product_results[25] + product_results[33] + product_results[43] + f_new[5] * (int64_t) g_new[2]+f_new[6]*2*(int64_t)g_new[1] + product_results[70] +
                 g_new[9]*2*(int64_t)f_new[2] + product_results[59];
    h_values[8] = f_new[0] * g_new[8] + f_new[7] * 2 * (int64_t) g_new[1] + product_results[36] + f_new[5] * 2 * (int64_t) g_new[3] + product_results[44] + g_new[5]*2*f_new[3] + g_new[6]*2*(int64_t)f_new[2] + 
                 f_new[7]*2*(int64_t) g_new[1] + product_results[80] + f_new[1]*(int64_t)g_new[8]*38;
    h_values[9] = f_new[0] * g_new[9] + product_results[17] + product_results[37] + product_results[47] +  product_results[57] + product_results[67] + product_results[76] + product_results[67] + 
                  f_new[8] * (int64_t) g_new[1] + f_new[9]*g_new[0];

    int64_t carry[10];

    carry[0] = (h_values[0] + (int64_t)(1L << 25)) >> 26;
    h_values[1] += carry[0];

    carry[1] = (h_values[1] + (int64_t)(1L << 24)) >> 25;
    h_values[2] += carry[1];

    carry[2] = (h_values[2] + (int64_t)(1L << 25)) >> 26;
    h_values[3] += carry[2];

    carry[3] = (h_values[3] + (int64_t)(1L << 24)) >> 25;
    h_values[4] += carry[3];

    carry[4] = (h_values[4] + (int64_t)(1L << 25)) >> 26;
    h_values[5] += carry[4];

    carry[5] = (h_values[5] + (int64_t)(1L << 24)) >> 25;
    h_values[6] += carry[5];

    carry[6] = (h_values[6] + (int64_t)(1L << 25)) >> 26;
    h_values[7] += carry[6];

    carry[7] = (h_values[7] + (int64_t)(1L << 24)) >> 25;
    h_values[8] += carry[7];

    carry[8] = (h_values[8] + (int64_t)(1L << 25)) >> 26;
    h_values[9] += carry[8];

    carry[9] = (h_values[9] + (int64_t)(1L << 24)) >> 25;
    h_values[0] += carry[9] * 19;

    carry[0] = (h_values[0] + (int64_t)(1L << 25)) >> 26;
    h_values[1] += carry[0];

    for(int i=0; i<10; i++){
        h_values[i] -= carry[i] * ((uint64_t) 1L << (25 + (i % 2)));
        h[i] = (int32_t) h_values[i];
    }
    

}