fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t i;
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

    int32_t g1_19 = 19 * g[1]; /* 1.959375*2^29 */
    int32_t g2_19 = 19 * g[2]; /* 1.959375*2^30; still ok */
    int32_t g3_19 = 19 * g[3];
    int32_t g4_19 = 19 * g[4];
    int32_t g5_19 = 19 * g[5];
    int32_t g6_19 = 19 * g[6];
    int32_t g7_19 = 19 * g[7];
    int32_t g8_19 = 19 * g[8];
    int32_t g9_19 = 19 * g[9];
    int32_t f1_2  = 2 * f[1];
    int32_t f3_2  = 2 * f[3];
    int32_t f5_2  = 2 * f[5];
    int32_t f7_2  = 2 * f[7];
    int32_t f9_2  = 2 * f[9];

    int64_t fg[10][10];

    /* 'Calculate all "f_i * g_j" computation only once and use the value when required" optimization idea */
    for (i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fg[i][j] = f[i] * (int64_t) g[j];
        }
    }

    int64_t h0 = fg[0][0] + fg[1][9] * 38 + fg[2][8] * 19 + fg[3][7] * 38 + fg[4][6] * 19
                 + fg[5][5] * 38 + fg[6][4] * 19 + fg[7][3] * 38 + fg[8][2] * 19 + fg[9][1] * 38;
    int64_t h1 = fg[0][1] + fg[1][0]  + fg[2][9] * 19 + fg[3][8] * 19 + fg[4][7] * 19
                 + fg[5][6] * 19 + fg[6][5] * 19 + fg[7][4] * 19 + fg[8][3] * 19 + fg[9][2] * 19;
    int64_t h2 = fg[0][2] + fg[1][1] * 2 + fg[2][0] + fg[3][9] * 38 + fg[4][8] * 19 
                 + fg[5][7] * 38 + fg[6][6] * 19 + fg[7][5] * 38 + fg[8][4] * 19 + fg[9][3] * 38;
    int64_t h3 = fg[0][3] + fg[1][2] + fg[2][1] + fg[3][0] + fg[4][9] * 19 + fg[5][8] * 19 + fg[6][7] * 19 
                 + fg[7][6] * 19 + fg[8][5] * 19 + fg[9][4] * 19;
    /*... Repeat this until h9 */

    int64_t carry0 = (h0 + (int64_t)(1L << 25)) >> 26; h1 += carry0; h0 -= carry0 * ((uint64_t) 1L << 26);
    int64_t carry4 = (h4 + (int64_t)(1L << 25)) >> 26; h5 += carry4; h4 -= carry4 * ((uint64_t) 1L << 26);
    /* Do this upto carry9 */

    /* finalize h9 */
    carry9 = (h9 + (int64_t)(1L << 24)) >> 25;
    h0 += carry9 * 19;
    h9 -= carry9 * ((uint64_t) 1L << 25);

    /* Finalize h0 */
    carry0 = (h0 + (int64_t)(1L << 25)) >> 26; 
    h1 += carry0; 
    h0 -= carry0 * ((uint64_t) 1L << 26);

    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    /*copy unto h9*/
}