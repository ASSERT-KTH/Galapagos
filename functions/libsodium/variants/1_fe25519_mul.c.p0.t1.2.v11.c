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

        // Additional variables g1_19 etc., f1_2 etc., h0 through h9
        /* Calculations for g1_19 etc., f1_2 etc., f0g0, f0g1_2 etc. until f9g9_38; with minor changes */
        // Statements carry0 to carry9, working out h0 through h9 and carrying over excess from each

        h[9] = (int32_t) h0;
        h[8] = (int32_t) h1;
        h[7] = (int32_t) h2;
        h[6] = (int32_t) h3;
        h[5] = (int32_t) h4;
        h[4] = (int32_t) h5;
        h[3] = (int32_t) h6;
        h[2] = (int32_t) h7;
        h[1] = (int32_t) h8;
        h[0] = (int32_t) h9;
}