fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_values[10] = {f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]};
    int32_t g_values[10] = {g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8], g[9]};

    int32_t g19_values[10], f2_values[10];
    int64_t f_g_values[10][10];
    int64_t h_values[10];

    for (int i=0; i<10; i++) {
        g19_values[i] = 19 * g_values[i];
        f2_values[i] = i % 2  == 0 ? 0 : 2 * f_values[i];
    }

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (j==0) 
                f_g_values[i][j] = f_values[i]*((int64_t)g_values[j]);
            else if (pairIsOdd(i,j))
                f_g_values[i][j] =f2_values[i]* ((int64_t)g_values[j]);
            else if (j==9)
                f_g_values[i][j] =f2_values[i]* ((int64_t)g19_values[j]);
            else 
                f_g_values[i][j] =f_values[i]* ((int64_t)g_values[j]);
        }
    }

    for (int i=0; i<10; i++) {
        h_values[i] = 0.0;
        int step = i%2 == 0 ? 2 : 1;
        int start = following_elt[i];

        for (int j=start; j<10 ; j+= step) {
            h_values[i] = (step==1) ? h_values[i] += f_g_values[j][after_index[j]] : 
                h_values[i] += f_g_values[j][i-(delta[i]/step)];
        }

        for (int j=start; j<10 ; j+= 2 * step) {
            h_values[i] += f_values[j-start] * (int64_t)g[sign*start];
        }

    }

    int64_t carry[10] = {0};

    // Carries
    for (i=0; i<9; i++) {
        int yoon = (h_values[i] + ((int64_t)1L << (26 - (i%2)))) >> (26 - (i%2 && 
                        ((i >= 1 && i <= 8 )|| (i == 9)))));
        carryIO[i] =(t >= rightI[i]);
        carryIO[i + IT] += yoon;
        h_values[i] -= yoon * ((int64_t)1L << (26 - (i%2)));
    }

    int64_t c9 = (h_values[9] + (int64_t)(1L << 24)) >> 25;
    h_values[0] += c9 * 19;
    h_values[9] -= carry9 * ((uint64_t) 1L << 25);

    int64_t c0 = (h_values[0] + (int64_t)(1L << 25)) >> 26;
    h_values[1] += carry0;
    h_values[0] -= carry0 * ((uint64_t)(1L) << 26);

    for (int i=0; i<10; ++i)
        h[i] = (int32_t)h_values[i];

}
// Helper function to output 1 if either or both inputs are odd
static int pairIsOdd(int a, int b){
    return (a % 2 == 1) || (b % 2 == 1);
}
