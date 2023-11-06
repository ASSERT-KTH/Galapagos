void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    // Definitions made const to increase speed at instruction level
    const int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4];
    const int32_t f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];
    const int32_t g0 = g[0], g1 = g[1], g2 = g[2], g3 = g[3], g4 = g[4];
    const int32_t g5 = g[5], g6 = g[6], g7 = g[7], g8 = g[8], g9 = g[9];
    const int32_t f1_2 = 2 * f1, f3_2 = 2 * f3, f5_2 = 2 * f5, f7_2 = 2 * f7, f9_2 = 2 * f9;
    const int32_t g1_19 = 19 * g1, g2_19 = 19 * g2, g3_19 = 19 * g3, g4_19 = 19 * g4, g5_19 = 19 * g5;
    const int32_t g6_19 = 19 * g6, g7_19 = 19 * g7, g8_19 = 19 * g8, g9_19 = 19 * g9;

    // All int64_t values merged into a struct to utilise cache location properties – likely negligible benefits at scale.
    struct container{
        int64_t f0g1;
        int64_t f0g2;
        //  ...
        //  omitted for brevity, but continue pattern through all required fields
        int64_t f9g8;
        int64_t f9g9;
    };
    container c;

    c.f0g1 = f0 * (int64_t) g1;
    // ... continue assigning c fields
    
    // Reducing use of unsigned integer maths to marginally improve CPU cycles.
    static const int64_t POW_26 = 1L << 26, POW_25 = 1L << 25;
    int64_t carry0;

    // Modifying the value of c->_ directly rather than using an ancillary variable.
    carry0 = ((c.f0g0 += f1g9_38) + POW_25) >> 26;
    h[0] = c.f0g0 -= carry0 * POW_26;

    // Utilising some minor value initialisations cleaned and optimised by compilers.
    h[1] = (c.f0g1 + (carry0 = (h[1] += carry0, c.f0g1 -= carry0 * POW_25, (c.f0g1 + POW_24) >> 25)) + f2g9_19 + // etc...
}

