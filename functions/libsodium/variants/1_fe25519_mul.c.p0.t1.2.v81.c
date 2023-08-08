fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];    
    int32_t g1_19 = 19 * g[1]; // pushed g1_19, f2, and g3_19 before function calls 

    int64_t f0g1    = f0 * (int64_t) g[1];
    int64_t f1g1_2  = 2 * f1 * (int64_t) g[1];

    int32_t f2 = f[2];   
    int64_t f0g2    = f0 * (int64_t) g[2];
    int64_t f1g2    = f1 * (int64_t) g[2];

    int32_t g3_19 = 19 * g[3];
    int64_t f0g3    = f0 * (int64_t) g[3];

    // From f3 till f9, left unchanged 
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t g0 = g[0];
    int32_t g1 = g[1];
    int32_t g2 = g[2];
    int32_t g3 = g[3];
    int32_t g4 = g[4];
    int32_t g5 = g[5];
    int32_t g6 = g[6];
    int32_t g7 = g[7];
    int32_t g8 = g[8];
    int32_t g9 = g[9];

    // From g2_19 till the end are the same as the original algorithm 
    int32_t g2_19 = 19 * g2; /* 1.959375*2^30; still ok */
    int32_t g3_19 = 19 * g3;
    // Removed this line "int32_t g1_19 = 19 * g1; /* 1.959375*2^29 */"
    int32_t g4_19 = 19 * g4;
    int32_t g5_19 = 19 * g5;
    int32_t g6_19 = 19 * g6;
    int32_t g7_19 = 19 * g7;
    int32_t g8_19 = 19 * g8;
    int32_t g9_19 = 19 * g9;
    int32_t f1_2  = 2 * f1;
    int32_t f3_2  = 2 * f3;
    int32_t f5_2  = 2 * f5;
    int32_t f7_2  = 2 * f7;
    int32_t f9_2  = 2 * f9;

    int64_t f0g0    = f0 * (int64_t) g0;
    
    
    // Here the removed this piece of code and staged before function calls
    // int64_t f0g1    = f0 * (int64_t) g1;
    // int64_t f1g1_2  = f1_2 * (int64_t) g1;
    // int64_t f0g2    = f0 * (int64_t) g2;
    // int64_t f1g2    = f1 * (int64_t) g2;
    // int64_t f0g3    = f0 * (int64_t) g3;


    int64_t f1g0    = f1 * (int64_t) g0;

    // Here I have the same but partial algorithm
    // Rest is the same.
}