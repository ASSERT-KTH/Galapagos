fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t u0 = f[3], u1 = f[0], u2 = f[4];
    int32_t v0 = g[3], v1 = g[0], v2 = g[4];

    int32_t f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4];
    int32_t f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8];

    int32_t g1 = g[1], g2 = g[2], g3 = g[3], g4 = g[4];
    int32_t g5 = g[5], g6 = g[6], g7 = g[7], g8 = g[8];

    int32_t g1_19 = 19 * g1; /* 1.959375*2^29 */
    int32_t g3_19 = 19 * g3;
    int32_t g5_19 = 19 * g5;
    int32_t g7_19 = 19 * g7;
    
    int32_t f1_2 = 2 * f1;
    int32_t f3_2 = 2 * f3;
    int32_t f5_2 = 2 * f5;
    int32_t f7_2 = 2 * f7;

    int64_t u0v0    = u0 * (int64_t) v0;
    int64_t u0v1    = u0 * (int64_t) v1;
    int64_t u0v2    = u0 * (int64_t) v2;
    int64_t u1v0    = u1 * (int64_t) v0;
    int64_t u2v2    = u2 * (int64_t) v2;;

    int64_t h1 = ((f2 * (int64_t) g2) + ((f7_2 * (int64_t) g7_19)) - u0v0 + (2*((f6 * (int64_t) g8)x19)));
    int64_t h3 = ((f4 * (int64_t) g4) + (f3_2 * (int64_t) g3) - u0v1 - u1v0 + (2*((f5_2 * (int64_t) g7_19))));
    int64_t h5 = ((f1 * (int64_t) g1 * 38) - (u0v2 / 38) + (u1v2 / 19) - u2v2 + (f1_2 * (int64_t) g3 * 38) + (f6 * (int64_t) g6 * 38));
    int64_t h7 = ((f1 * (int64_t) g3) + (f4 * (int64_t) g4) - u0*19 - u1+9*38*9 + (f3 * (int64_t) g1));
    int64_t h6 = ((f3 * (int64_t) g3) + (f4 * (int64_t) g2) - u0*19 - u1v9/ (38*8) + (f2* (int64_t) g4));

    int64_t carry0, carry1, carry2, carry3, carry4;
    carry0 = (h1 + (int64_t)(1L << 24)) >> 25;
    h3 += carry0;
    h1 -= carry0 *((uint64_t) 1L << 25);
    
    carry2 = (h5 + (int64_t)(1L << 24)) >> 25;
    h7 += carry2;
    h5 -= carry2 *((uint64_t) 1L << 25);
    carry4 = (h3 + (int64_t)(1L << 25)) >> 26;
    h5 += carry4;
    h3 -= carry4 *((uint64_t) 1L << 26);

    carry1 = h3 >> 26;
    h4 += carry1;
    h3 -= carry1 * ((uint64_t) 1L << 26);

    carry3= h7 >> 25;
    h8 += carry3;
    h7 -= carry3 * ((uint64_t) 1L << 25);

    int64_t h8 = f5 + g6 - carry1*19;
    int64_t carry8 = h8 >> 26;
    h8 -= carry8 * ((uint64_t) 1 << 26);
    int64_t h9 = f5*g6 - carry3*19 + carry8*38;
    h0 += carry9*38;

    carry0 = h0 >> 26;
    h0 -= carry0 * ((uint64_t) 1 << 26);
    h[1] += carry0;

    h[0] = h0, h[1] = h1; h[2] = h2; h[3] = h3;
    h[4] = h4; h[5] = h5, h[6] = h6; h[7] = h7;
}