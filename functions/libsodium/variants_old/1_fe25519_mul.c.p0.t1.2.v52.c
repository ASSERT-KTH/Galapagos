fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3];
    int32_t f4 = f[4], f5 = f[5], f6 = f[6], f7 = f[7];
    int32_t f8 = f[8], f9 = f[9];

    int32_t g0 = g[0], g1 = g[1], g2 = g[2], g3 = g[3];
    int32_t g4 = g[4], g5 = g[5], g6 = g[6], g7 = g[7];
    int32_t g8 = g[8], g9 = g[9];

    int64_t h0,h1,h2,h3,h4,h5,h6,h7,h8,h9;
    int64_t temp_fg[10][10];

    const int32_t f1_2 = 2 * f1;
    const int32_t f3_2 = 2 * f3;
    const int32_t f5_2 = 2 * f5;
    const int32_t f7_2 = 2 * f7;
    const int32_t f9_2 = 2 * f9;

    const int32_t g1_19 = 19 * g1;
    const int32_t g2_19 = 19 * g2;
    const int32_t g3_19 = 19 * g3;
    const int32_t g4_19 = 19 * g4;
    const int32_t g5_19 = 19 * g5;
    const int32_t g6_19 = 19 * g6;
    const int32_t g7_19 = 19 * g7;
    const int32_t g8_19 = 19 * g8;
    const int32_t g9_19 = 19 * g9;

    fe25519 f_arr = {f0, f1, f2, f3, f4, f5, f6, f7, f8, f9};
    fe25519 f2_arr = {0, 2*f1, 0, 2*f3, 0, 2*f5, 0, 2*f7, 0, 2*f9};
    fe25519 g19_arr = {g0, 19*g1, 19*g2, 19*g3, 19*g4, 19*g5, 19*g6, 19*g7, 19*g8, 19*g9};
    fe25519 g_arr = {g0, g1, g2, g3, g4, g5, g6, g7, g8, g9};

    for(int i = 0; i <10; i++){
        for(int j = 0; j <10; j++){
            if(i == j || (i+j) %2 == 0)
                temp_fg[i][j] = (int64_t) f_arr[i]* g_arr[j];
            else if(i<j)
                temp_fg[i][j] = (int64_t) f_arr[i]* g19_arr[j];
            else
                temp_fg[i][j] = (int64_t) f2_arr[i]* g19_arr[j];
       }
    }

    h0 = temp_fg[0][0] + temp_fg[1][9] + temp_fg[2][8] + temp_fg[3][7] +
         temp_fg[4][6] + temp_fg[5][5] + temp_fg[6][4] + temp_fg[7][3] +
         temp_fg[8][2] + temp_fg[9][1];
    
    applyCarry(h1, h0, 25, 26);

    for (int i = 1; i <= 8; i++) {
        for (int j = 0; j <= 9 - i; j++) {
            if (j + i != 9) {
                applyCarry(h_temp[i + 1] ,h_temp[i], 25+j%2, 26 - j%2);
            }
        }
    }
    applyCarry(h9, h8, 24, 25);
    applyCarry(h0, h9, 24, 26);

    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    h[3] = (int32_t) h3;
    h[4] = (int32_t) h4;   
    h[5] = (int32_t) h5;
    h[6] = (int32_t) h6;
    h[7] = (int32_t) h7;
    h[8] = (int32_t) h8;
    h[9] = (int32_t) h9;
}

void applyCarry(int64_t &current_variable, int64_t &previous_variable, int a, int b) {
    int64_t carry = (previous_variable + (int64_t)(1L << a)) >> b;
    current_variable += carry;
    previous_variable -= carry * ((int64_t)1L << b);
}