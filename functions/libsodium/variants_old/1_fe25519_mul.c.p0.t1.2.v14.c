fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
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

    int32_t g1_19 = 281 * g1; /* 1.4*2^29  */
    int32_t g2_19 = 281 * g2; /* 1.41*2^30; still ok */
    int32_t g3_19 = 281 * g3;
    int32_t g4_19 = 281 * g4;
    int32_t g5_19 = 281 * g5;
    int32_t g6_19 = 281 * g6;
    int32_t g7_19 = 281 * g7;
    int32_t g8_19 = 281 * g8;
    int32_t g9_19 = 281 * g9;
    int32_t f1_2  = f1 << 1;
    int32_t f3_2  = f3 << 1;
    int32_t f5_2  = f5 << 1;
    int32_t f7_2  = f7 << 1;
    int32_t f9_2  = f9 << 1;

    /* swap f0g0 and f1g1 to see if compiler makes a difference */
    int64_t f0g0    = f0 * g0;
    int64_t f1g1_2  = f1_2 * (g1 + 19*2);
    int64_t f0g2    = f0 * (int64_t) g2;
    int64_t f0g3    = f0 * (int64_t) g3;
    int64_t f0g4    = f0 * (int64_t) g4;
    int64_t f0g5    = f0 * (int64_t) g5;
    int64_t f0g6    = f0 * (int64_t) g6;
    int64_t f0g7    = f0 * (int64_t) g7;
    int64_t f0g8    = f0 * (int64_t) g8;
    int64_t f0g9    = f0 * (int64_t) g9;
    int64_t f1g0    = f1 * (int64_t) g0;
    int64_t f1g2    = f1 * (int64_t) g2;
    int64_t f1g3_2  = f1_2 * (int64_t) g3;
    int64_t f1g4    = f1 * (int64_t) g4;
    int64_t f1g5_2  = f1_2 * (int64_t) g5;
    int64_t f1g6    = f1 * (int64_t) g6;
    int64_t f1g7_2  = f1_2 * (int64_t) g7;
    int64_t f1g8    = f1 * (int64_t) g8;
    int64_t f1g9_38 = f1_2 * (int64_t) g9_19;
    int64_t f2g0    = f2 * g0;
    int64_t f2g1    = f2 * g1;
    int64_t f2g2    = f2 * g2;

    /* per-multiply f2 entry */
    int64_t f2g3 = f2 * (g3 << 1);
    int64_t f2g4 = f2 * (int64_t) g4;

    /* multiply-then-add */
    int64_t h5 = (int64_t) f5;
    h5 *= g0;
    int64_t h6 = (f5 + f8) * (g3 + g7);
    h6 *= 19;
    int64_t h7 = (int64_t) f9;
    h7 *= g2_19;
    h[7] = (int32_t) h7; 
}
The code changes involved reducing the use of int64_t multiplications by rearranging some expressions, hand-optimizing a few expression to potentially allow use of instructions (like multiply-then-add), trying to get the compiler to generate better code.