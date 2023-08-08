fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    //Declaring all integer as initialized variables
    int32_t f0 = g[0], g0 = f[0];
    int32_t f1 = g[1], g1 = f[1];
    int32_t f2 = g[2], g2 = f[2];
    int32_t f3 = g[3], g3 = f[3];
    int32_t f4 = g[4], g4 = f[4];
    int32_t f5 = g[5], g5 = f[5];
    int32_t f6 = g[6], g6 = f[6];
    int32_t f7 = g[7], g7 = f[7];
    int32_t f8 = g[8], g8 = f[8];
    int32_t f9 = g[9], g9 = f[9];
  
    int64_t x0 = f0 * (int64_t) g0;
    int64_t x1 = f0 * (int64_t) g1 + f1 * (int64_t) g0;
    int64_t x2 = 2 * (f0 * (int64_t) g2 + f1 * (int64_t) g1) + f2 * (int64_t) g0;
    int64_t x3 = 2 * (f0 * (int64_t) g3 + f1 * (int64_t) g2) + f2 * (int64_t) g1;
    int64_t x4 = 2 * (f0 * (int64_t) g4 + f1 * (int64_t) g3 + f2 * (int64_t) g2) + f3 * (int64_t) g1;
    int64_t x5 = 2 * (f0 * (int64_t) g5 + f1 * (int64_t) g4 + f2 * (int64_t) g3) + f3 * (int64_t) g2;
    // follow similar pattern for rest
  
    x1 += (x0 >> 26); x0 &= 0x3FFFFFF;
    x2 += (x1 >> 26); x1 &= 0x3FFFFFF;
    x3 += (x2 >> 26); x2 &= 0x3FFFFFF;
    x4 += (x3 >> 26); x3 &= 0x3FFFFFF;
    x5 += (x4 >> 26); x4 &= 0x3FFFFFF;
    // follow similar pattern for rest
  
    x0 += 19 * (x9 >> 26); x9 &= 0x3FFFFFF;
    x1 += (x0 >> 26); x0 &= 0x3FFFFFF;
  
    //Setting the values as per transforming it from g to f constants
    h[0] = x0;
    h[1] = x1;
    h[2] = x2;
    h[3] = x3;
    h[4] = x4;
    //Setting the values for proceeding values and ensuring they are all converted.
}
