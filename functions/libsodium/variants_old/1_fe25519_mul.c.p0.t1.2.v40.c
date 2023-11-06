fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[9];
    int32_t f1 = f[8];
    int32_t f2 = f[7];
    int32_t f3 = f[6];
    int32_t f4 = f[5];
    int32_t f5 = f[4];
    int32_t f6 = f[3];
    int32_t f7 = f[2];
    int32_t f8 = f[1];
    int32_t f9 = f[0];

    int32_t g0 = g[9];
    int32_t g1 = g[8];
    int32_t g2 = g[7];
    int32_t g3 = g[6];
    int32_t g4 = g[5];
    int32_t g5 = g[4];
    int32_t g6 = g[3];
    int32_t g7 = g[2];
    int32_t g8 = g[1];
    int32_t g9 = g[0];

    int32_t g1_19 = g8 * 19;
    int32_t g2_19 = g7 * 19;
    int32_t g3_19 = g6 * 19;
    int32_t g4_19 = g5 * 19;
    int32_t g5_19 = g4 * 19;
    int32_t g6_19 = g3 * 19;
    int32_t g7_19 = g2 * 19;
    int32_t g8_19 = g1 * 19;
    int32_t g9_19 = g0 * 19;
    int32_t f1_2  = 2 * f8;
    int32_t f3_2  = 2 * f6;
    int32_t f5_2  = 2 * f4;
    int32_t f7_2  = 2 * f2;
    int32_t f9_2  = 2 * f0;

    int64_t f0g0    = f9 * (int64_t) g9;
    int64_t f0g1    = f9 * (int64_t) g8;
    int64_t f0g2    = f9 * (int64_t) g7;
    int64_t f0g3    = f9 * (int64_t) g6;
    int64_t f0g4    = f9 * (int64_t) g5;
    int64_t f0g5    = f9 * (int64_t) g4;
    int64_t f0g6    = f9 * (int64_t) g3;
    int64_t f0g7    = f9 * (int64_t) g2;
    int64_t f0g8    = f9 * (int64_t) g1;
    int64_t f0g9    = f9 * (int64_t) g0;
    int64_t f1g0    = f8 * (int64_t) g9;
    int64_t f1g1_2  = f8_2 * (int64_t) g8;
    int64_t f1g2    = f8 * (int64_t) g7;
    int64_t f1g3_2  = f8_2 * (int64_t) g6;
    int64_t f1g4    = f8 * (int64_t) g5;
    int64_t f1g5_2  = f8_2 * (int64_t) g4;
    int64_t f1g6    = f8 * (int64_t) g3;
    int64_t f1g7_2  = f8_2 * (int64_t) g2;
    int64_t f1g8    = f8 * (int64_t) g1;
    int64_t f1g9_38 = f8_2 * (int64_t) g0_19;
    int64_t f2g0    = f7 * (int64_t) g9;
    int64_t f2g1    = f7 * (int64_t) g8;
    int64_t f2g2    = f7 * (int64_t) g7;
    int64_t f2g3    = f7 * (int64_t) g6;
    int64_t f2g4    = f7 * (int64_t) g5;
    int64_t f2g5    = f7 * (int64_t) g4;
    int64_t f2g6    = f7 * (int64_t) g3;
    int64_t f2g7    = f7 * (int64_t) g2;
    int64_t f2g8_19 = f7 * (int64_t) g1_19;
    int64_t f2g9_19 = f7 * (int64_t) g0_19;
    int64_t f3g0    = f6 * (int64_t) g9;
    int64_t f3g1_2  = f6_2 * (int64_t) g8;
    int64_t f3g2    = f6 * (int64_t) g7;

    // Code continues... 
    // (Note: Since original code is huge, illustrated part for these transformations has been kept short.)
}