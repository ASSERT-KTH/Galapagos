fe25519_sq(fe25519 h, const fe25519 f)
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

    int32_t f2x[] = {2*f0, 2*f1, 2*f2, 2*f3, 2*f4, 2*f5, 2*f6, 2*f7};
    int32_t fx_2_38[] = {38*f5, 19*f6, 38*f7,19*f8,38*f9};

    int64_t h_calc[10][10] = {};
    for (int i=0 ; i<10 ; i++)
    {
        for (int j=i ; j<10 ; j++) 
        {
            if (i == j) 
            {
                h_calc[i][j] = f[i] * (int64_t)f[j];
            } 
            else 
            {
                h_calc[i][j] = f2x[i] * (int64_t)f[j];
                h_calc[j][i] = h_calc[i][j];
            }
        }
    }

    int64_t h_val[] = {h_calc[0][0] + h_calc[1][9] + h_calc[2][8] + h_calc[3][7] + h_calc[4][6] + h_calc[5][5],
                       h_calc[0][1] + h_calc[2][9] + h_calc[3][8] + h_calc[4][7] + h_calc[5][6],
                       h_calc[0][2] + h_calc[1][1] + h_calc[3][9] + h_calc[4][8] + h_calc[5][7] + h_calc[6][6],
                       h_calc[0][3] + h_calc[1][2] + h_calc[4][9] + h_calc[5][8] + h_calc[6][7],
                       h_calc[0][4] + h_calc[1][3] + h_calc[2][2] + h_calc[5][9] + h_calc[6][8] + h_calc[7][7],
                       h_calc[0][5] + h_calc[1][4] + h_calc[2][3] + h_calc[6][9] + h_calc[7][8],
                       h_calc[0][6] + h_calc[1][5] + h_calc[2][4] + h_calc[3][3] + h_calc[7][9] + h_calc[8][8],
                       h_calc[0][7] + h_calc[1][6] + h_calc[2][5] + h_calc[3][4] + h_calc[8][9],
                       h_calc[0][8] + h_calc[1][7] + h_calc[2][6] + h_calc[3][5] + h_calc[4][4] + h_calc[9][9],
                       h_calc[0][9] + h_calc[1][8] + h_calc[2][7] + h_calc[3][6] + h_calc[4][5]};

    int64_t carry[10] = {};

    for(int i=0; i<10; ++i)
    {
        int64_t unshiftedCarry = (h_val[i] + (int64_t)(1L << (i == 1 || i == 3 || i == 5 || i == 9 ? 24 : 25)));
        carry[i] = unshiftedCarry >> (i == 1 || i == 3 || i == 5 || i == 9 ? 25 : 26);
        h_val[(i + 1)%10] += carry[i];
        h_val[i] -= carry[i] * ((uint64_t) 1L << (i == 1 || i == 3 || i == 5 || i == 9 ? 25 : 26));        
    }
    int64_t carryAll = (h_val[0] + (int64_t)(1L << 25)) >> 26;
    h_val[1] += carryAll;
    h_val[0] -= carry[1] * ((uint64_t) 1L << 26);

    for (int i = 0; i < 10; i++)
        h[i] = (int32_t) h_val[i];
}