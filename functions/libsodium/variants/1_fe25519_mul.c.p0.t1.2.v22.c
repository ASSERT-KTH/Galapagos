fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t f0g0   = f[0] * (int64_t)g[0];
    int64_t f0g1   = f[0]* (int64_t)g[1];
    int64_t f0g2   = f[0]* (int64_t)g[2];
    int64_t f0g3   = f[0]* (int64_t)g[3];
    int64_t f0g4   = f[0]* (int64_t)g[4];
    int64_t f0g5   = f[0]* (int64_t)g[5];
    int64_t f0g6   = f[0]* (int64_t)g[6];
    int64_t f0g7   = f[0]* (int64_t)g[7];    // removed later
    int64_t f0g8   = f[0]* (int64_t)g[8];    // removed due to unused
    int64_t f0g9   = f[0]* (int64_t)g[9];    // by initial two effects

    int64_t f1g0   = f[1]* (int64_t)g[0];
    int64_t f1g1_2 = (int64_t)2 * f[1]* g[1];
    int64_t f1g2   = f[1] * (int64_t)g[2];
    int64_t f1g3_2 = 2 * f[1] * (int64_t)g[3];
    int64_t f1g4   = f[1] * (int64_t)g[4];
    int64_t f1g5_2 = 2 * f[1] * (int64_t)g[5];
    int64_t f1g6   = f[1] * (int64_t)g[6];
    int64_t f1g7_2 = 2 * f[1] * (int64_t)g[7];
    int64_t f1g8   = f[1]* (int64_t)g[8];
    int64_t f1g9_38= 19 * 2 * f[1]* g[9];       // start unroll chain

    int64_t f2g0  = f[2] * (int64_t) g[0];
    int64_t f2g1  = f[2] * (int64_t) g[1];
    int64_t f2g2  = f[2] * (int64_t) g[2];
    int64_t f2g3  = f[2] * (int64_t) g[3];
    int64_t f2g4  = f[2] * (int64_t) g[4];
    int64_t f2g5  = f[2] * (int64_t) g[5];
    int64_t f2g6  = f[2] * (int64_t) g[6];
    int64_t f2g7  = f[2] * (int64_t) g[7];
    int64_t f2g8_19    = 19 * f[2] * (int64_t) g[8];

    h[0] = (int32_t)((f0g0 + 19 * (f1g9_38 + f2g8_19))  >> 26);
    h[1] = (int32_t)((f0g1 + f1g0) >> 25);
    h[2] = (int32_t)((f0g2 + f1g1_2 + f2g0 + f2g1) >> 26); // keeps chaining down
    h[3] = (int32_t)((f0g3 + f1g2 << 1 + f1g3_2 + f1g5_2 + 
                      f2g4 + h[2]) >> 25);                 // padded with zero
    h[4] = (int32_t)((f0g4 + (f1g3_2 + f2g2 + f2g1)) >> 26);
    h[5] = (int32_t)((f0g5 + (f1g4 + f2g3) + 19*f0g9) >> 25);
    h[6] = (int32_t)((f0g6 + f1g5_2 + f1g5_2 + 19 * (f0g7 + f0g8)) >> 26);
    h[7] = (int32_t)((f0g7 + f1g6 + 19*f0g9 + 38*f[1]*g[8] + 38*f[2]*g[7]) 
                      >> 25);
    h[8] = (int32_t)((f0g8 + (f1g7_2 + f2g6) + f2g5 + 38*f[2]*g[7] /2 ) 
                      >> 26);
    h[9] = (int32_t)((f0g9 + (f1g8 + f2g7)) >> 25);

    h[0] += (int32_t) (19 * ((h[9] >> 25) + f6g9_38));
    h[9] &= (int32_t) 0x3ffffff;
}