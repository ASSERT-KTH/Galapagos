void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0xffffffffffffffffULL;
    uint64_t r0, r1, r2, r3, r4;
    uint64_t f0, f1, f2, f3, f4;
    uint64_t f2_38, f3_38, f4_38, f5_38;
    uint64_t g0, g1, g2, g3, g4;

    f0 = f[0];
    f1 = f[1];
    f2 = f[2];
    f3 = f[3];
    f4 = f[4];

    g0 = g[0];
    g1 = g[1];
    g2 = g[2];
    g3 = g[3];
    g4 = g[4];

    f2_38 = 38 * f2; 
    f3_38 = 38 * f3;
    f4_38 = 38 * f4; 

    r0 = (2 * f0 + f1) * g0 + (2 * (f2_38) * g4 ) + (1 * f1) * g4 + 19 * (f3_38 * g2 + f4_38 * g1);
    r1 = (f0 + 2 * f1 + 38 * f2) * g1 + 19 * ((2 * f3_38) * g3 + (2 * f4_38) * g2);
    r2 = (f0 + 2 * f1 + f2 + 2 * f3_38) * g2 + 19 * ((2 * f4_38) * g3);
    r3 = (f0 + f1 + f2 + 2 * f3_38 + f4_38) * g3;
    r4 = (f0 + f1 + f2 + f3 + 2 * f4_38) * g4;
    
    r1 += r0 >> 51; r0 &= mask;
    r2 += r1 >> 51; r1 &= mask;
    r3 += r2 >> 51; r2 &= mask;
    r4 += r3 >> 51; r3 &= mask;
    r0 += 19 * (r4 >> 51); r4 &= mask;
    r1 += r0 >> 51; r0 &= mask;
    r2 += r1 >> 51; r1 &= mask;

    h[0] = r0;
    h[1] = r1;
    h[2] = r2;
    h[3] = r3;
    h[4] = r4;
}