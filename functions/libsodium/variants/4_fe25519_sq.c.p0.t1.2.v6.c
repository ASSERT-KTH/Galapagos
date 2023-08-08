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

    int64_t carry0, carry1, carry2, carry3, carry4, 
            carry5, carry6, carry7, carry8, carry9;

    int64_t h0, h1, h2, h3, h4, h5, h6, h7, h8, h9;

    int32_t f_coeff[10][2] = {
                            {2 * f0, 38 * f0}, {2 * f1, 38 * f1}, {2 * f2, 19 * f2}, 
                            {2 * f3, 38 * f3}, {2 * f4, 19 * f4}, {2 * f5, 38 * f5}, 
                            {2 * f6, 19 * f6}, {2 * f7, 38 * f7}, {2 * f8, 19 * f8}, 
                            {2 * f9, 38 * f9}
                            };

    int64_t f_prod[10][10];
                            
    for(int i = 0; i < 10; ++i ) {
        for(int j = 0; j < 10; ++j ) {
            if(i >= j) {
                f_prod[i][j] = f[i] * (int64_t)f[j];
                f_prod[j][i] = f_prod[i][j];
            }
        }
    }

    h0 = f_prod[0][0] + f_prod[1][9] * 38 + f_prod[2][8] * 19 + f_prod[3][7] * 38 + f_prod[4][6] * 19 + f_prod[5][5] * 38;
    h1 = f_prod[0][1] * 2 + f_prod[2][9] * 38 + f_prod[3][8] * 19 + f_prod[4][7] * 38 + f_prod[5][6] * 19;

    /* repeated same procedure for h2 to h9, where indices are increamented */

    h0 = h0 + (1L << 25);
    carry0 = h0 >> 26;
    h0 = h0 - carry0 * ((uint64_t) 1L << 26);

    /* repeated same procedure for h1 to h9, where indices are increamented */

    carry1 = (h1 + (int64_t)(1L << 24)) >> 25;  

    /* followed the same steps until the end of the function headers { }  */
}
