void fe25519_sq(fe25519 h, const fe25519 f)
{
    int i;
    int64_t temp_h[10], carry[10];

    for (i = 0; i < 10; i++)
    {
        temp_h[i] = 0;
        carry[i] = 0;
    }

    int32_t f_constant[] = {2, 2, 2, 2, 2, 38, 19, 38, 19, 38};
    int64_t f_mult[10][10];

    for (i = 0; i < 10; i++)
    {
        f_mult[i][i] = f[i] * (int64_t)f[i]; 
        int j;
        for (j = i+1; j < 10; j++)
        {
            f_mult[i][j] = f_constant[i] * f[i] * (int64_t)f[j] ; 
            f_mult[j][i] = f_mult[i][j];
        }
    }

    temp_h[0] = f_mult[0][0] + f_mult[1][9] + f_mult[2][8] + f_mult[3][7] + f_mult[4][6] + f_mult[5][5];
    temp_h[1] = f_mult[0][1] + f_mult[2][9] + f_mult[3][8] + f_mult[4][7] + f_mult[5][6] ;
    temp_h[2] = f_mult[0][2] + f_mult[1][1] + f_mult[3][9] + f_mult[4][8] + f_mult[5][7] + f_mult[6][6];
    temp_h[3] = f_mult[0][3] + f_mult[1][2] + f_mult[4][9] + f_mult[5][8] + f_mult[6][7] ;
    temp_h[4] = f_mult[0][4] + f_mult[1][3] + f_mult[2][2] + f_mult[5][9] + f_mult[6][8] + f_mult[7][7];
    temp_h[5] = f_mult[0][5] + f_mult[1][4] + f_mult[2][3] + f_mult[6][9] + f_mult[7][8];
    temp_h[6] = f_mult[0][6] + f_mult[1][5] + f_mult[2][4] + f_mult[3][3] + f_mult[7][9] + f_mult[8][8];
    temp_h[7] = f_mult[0][7] + f_mult[1][6] + f_mult[2][5] + f_mult[3][4] + f_mult[8][9] ;
    temp_h[8] = f_mult[0][8] + f_mult[1][7] + f_mult[2][6] + f_mult[3][5] + f_mult[4][4] + f_mult[9][9];
    temp_h[9] = f_mult[0][9] + f_mult[1][8] + f_mult[2][7] + f_mult[3][6] + f_mult[4][5];

    int carry_neg[10] = {26, 25, 26, 25, 26, 25, 26, 25, 26, 25};
    int neg_mult[10] = {1, 1, 19, 1, 1, 1, 1, 1, 19, 19};
    int carry_small[10] = {25, 24, 25, 24, 25, 24, 25, 24, 25, 24};

    for (i = 0; i < 9; i++)
    {
        carry[i] = (temp_h[i] + (int64_t)(1L << carry_small[i])) >> carry_neg[i];
        temp_h[i+1] += carry[i];
        temp_h[i] -= carry[i] * ((uint64_t) 1L << carry_neg[i]);
    }

    carry[9] = (temp_h[9] + (int64_t)(1L << carry_small[9])) >> carry_neg[9];
    temp_h[0] += carry[9] * neg_mult[i];
    temp_h[9] -= carry[9] * ((uint64_t) 1L << carry_neg[9]);

    carry[0] = (temp_h[0] + (int64_t)(1L << carry_small[0])) >> carry_neg[0];
    temp_h[1] += carry[0];
    temp_h[0] -= carry[0] * ((uint64_t) 1L << carry_neg[0]);

    for (i = 0; i < 10; i++)
    {
        h[i] = (int32_t)temp_h[i];
    }
}
