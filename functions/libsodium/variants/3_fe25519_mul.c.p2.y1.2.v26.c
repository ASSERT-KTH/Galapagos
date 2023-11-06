fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f1_2  = f[1] * 2;
    int32_t f3_2  = f[3] * 2;
    int32_t f5_2  = f[5] * 2;
    int32_t f7_2  = f[7] * 2;
    int32_t f9_2  = f[9] * 2;
    int32_t g1_19 = 19 * g[1];
    int32_t g2_19 = 19 * g[2];
    int32_t g3_19 = 19 * g[3];
    int32_t g4_19 = 19 * g[4];
    int32_t g5_19 = 19 * g[5];
    int32_t g6_19 = 19 * g[6];
    int32_t g7_19 = 19 * g[7];
    int32_t g8_19 = 19 * g[8];
    int32_t g9_19 = 19 * g[9];

    int64_t f5g1_2 = f5_2 * (int64_t) g[1];    
    int64_t f0g0  =  f[0] * (int64_t) g[0];
    int64_t f0g9  =  f[0] * (int64_t) g[9];
    int64_t f0g1  =  f[0] * (int64_t) g[1];
    int64_t f0g8  =  f[0] * (int64_t) g[8];
    int64_t f0g7  =  f[0] * (int64_t) g[7];
    int64_t f3g3_2  = f3_2 * (int64_t) g[3];
    int64_t f2g2  =  f[2] * (int64_t) g[2];
    int64_t f6g6_19 = f[6] * (int64_t) g6_19;
    int64_t f1g1_2 = f1_2 * (int64_t) g[1];
    int64_t f7g7_19 = f[7] * (int64_t) g7_19;
    int64_t f4g4  = f[4] * (int64_t) g[4];
    int64_t f8g8_19 = f[8] * (int64_t) g8_19;
    
    int64_t h0 = f0g0 + f1_2 * (int64_t) g9_19 + f2g2 * g8_19 + f3_2 * g7_19 * 19 +
                 f4g4 * g6_19 + f5g1_2 * g5_19 + f6g6_19 + f7_2 * (int64_t) g[3] * 19 + 
                 f8g8_19 + f9_2 * (int64_t) g[1] * 19;
                   
    int64_t h2 = f0g0 * 2 + f1g1_2+ f2g2 + f3_2 * (int64_t) g[9]*19 + f4g4 * g8_19 +
                f5g1_2* g7_19 + f6g6_19 * 2 + f7_2 * g5_19 + f8g8_19 *2 +
                f9_2* (int64_t) g[3]*19;

    int64_t h4 = f0g0 * 4 + f1_2 *( int64_t) g[1] + f2g2 * 4 + f3_2 * g3_2 *2 +
                f4g4 + f5g1_2 * g9_19 + f6g6_19 * 4 + f7_2 * g7_19 *2 + f8g8_19 +
                f9_2 * (int64_t) g5_19;

    int64_t h6 = f0g0 * 8 + f1g1_2*2 + f2g2 * 8 + f3_2 * (int64_t) g[3] +
                f4g4 * 8 + f5_2 * ( int64_t) g[5] + f6g6_19 + f7g7_19 *2 + 
                f4g4* g8_19 + f9_2 * g7_19;

    int64_t h8 = f0g0 * 19 + f1_2 *g1_19 + f2g2 * 19 + f3g3_2 * 2 +
                f4g4 * 19 + f5g1_2 * g9_19 + f6_19 (int64_t) g[6] +
                f7g7_19 * 2 + f8g8_19 + f9_2 * g7_19;
    
    h[0] = ( h0 + ((uint64_t)1 << 25)) >> 26;
    h[1] = h0  >> 25;
    h[2] = ( h2 + ((uint64_t)1 << 25)) >> 26;
    h[3] = h1  >> 25;
    h[4] = ( h4 + ((uint64_t)1 << 25)) >> 26;
    h[5] = h4  >> 25;
    h[6] = ( h6 + ((uint64_t)1 << 25)) >> 26;
    h[7] = h5 >>25;
    h[8] = ( h8 + ((uint64_t)1 << 25)) >> 26;
    h[9] = h8>>25;

    return;

}
