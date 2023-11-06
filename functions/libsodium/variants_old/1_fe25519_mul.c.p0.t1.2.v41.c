fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t h0, h1, h2, h3, h4, h5, h6, h7, h8, h9;
    int64_t f0, f1, f2, f3, f4, f5, f6, f7, f8, f9;
    f0 = f[0];
    f1 = f[1];
    f2 = f[2];
    f3 = f[3];
    f4 = f[4];
    f5 = f[5];
    f6 = f[6];
    f7 = f[7];
    f8 = f[8];
    f9 = f[9];
    
    int64_t g0, g1, g2, g3, g4, g5, g6, g7, g8, g9;
    g0 = g[0];
    g1 = g[1];
    g2 = g[2];
    g3 = g[3];
    g4 = g[4];
    g5 = g[5];
    g6 = g[6];
    g7 = g[7];
    g8 = g[8];
    g9 = g[9];

    int64_t g1_19, g2_19, g3_19, g4_19, g5_19, g6_19, g7_19, g8_19, g9_19; 
    int64_t f1_2, f3_2, f5_2, f7_2, f9_2;
    
    g1_19 = 19 * g1;
    g2_19 = 19 * g2;
    g3_19 = 19 * g3;
    g4_19 = 19 * g4;
    g5_19 = 19 * g5;
    g6_19 = 19 * g6;
    g7_19 = 19 * g7;
    g8_19 = 19 * g8;
    g9_19 = 19 * g9;
    
    f1_2  = 2 * f1;
    f3_2  = 2 * f3;
    f5_2  = 2 * f5;
    f7_2  = 2 * f7;
    f9_2  = 2 * f9;

    int64_t h0h9_38, h1h8_19, h2h7_38, h3h6_19, h4h5_38;

    h0h9_38 = f0*f9_2;
    h1h8_19 = f1*f8;
    h2h7_38 = f2*f7_2;
    h3h6_19 = f3*f6;
    h4h5_38 = f4*f5_2;

    int64_t r;

    r = g0*h0h9_38 + g1*h1h8_19 + g2*h2h7_38 + g3*h3h6_19 + g4*h4h5_38;

    /* bits stay within exact size of r because of: c-bit integers, multiplying by
       25 bits smaller than pp25519 prime active in f */

    fe25519_freeze_short(r); /* ensures that -r->vy fits into 25 bits */

    r *= 19;

    /* from now on the value may underflow mod q */

    r += h0 & 0xFFFFFFFFFFFFFULL;              /* 0000PPPPPPPPSSSSS doesn't overflow */
    f0 &= 0xFFFFFFFFFFC00000ULL;

    h[0] = r;
    h[1] = h1 + (r >> 26); h[0] &= 0x3FFFFFF;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
    h[5] = h5;
    h[6] = h6;
    h[7] = h7;
    h[8] = h8;
    h[9] = h9;
}
