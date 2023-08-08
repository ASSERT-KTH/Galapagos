fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_values[10];
    for(int j = 0; j < 10; j++){
        f_values[j] = f[j];
    }

    int32_t lesser_F[10];
    for(int i=0; i<10; i++) {
        lesser_F[i] = 2 * f_values[i];
    }
    lesser_F[5] = 38 * f_values[5];
    lesser_F[6] = 19 * f_values[6];
    lesser_F[7] = 38 * f_values[7];
    lesser_F[8] = 19 * f_values[8];
    lesser_F[9] = 38 * f_values[9];

    int64_t F_mat[45];
    for(int n = 0; n < 10; n++){
        for(int m = n; m < 10; m++){
            F_mat[(((m+1)*m)>>1)+n] = (m==n) ? (n==2 || n==4) ? lesser_F[n] * (int64_t)f_values[m] : 
                                  lesser_F[n] * (int64_t)lesser_F[m]
                                : lesser_F[n] * (int64_t)f_values[m];
        }
    }

    int64_t h_values[10] = {
        F_mat[0]+F_mat[42]+F_mat[29]+F_mat[19]+F_mat[11]+F_mat[26], /* 0 */
        F_mat[1]+F_mat[30]+F_mat[20]+F_mat[12]+F_mat[6],           /* 1 */
        F_mat[2]+F_mat[43]+F_mat[31]+F_mat[21]+F_mat[13]+F_mat[8]    , /* 2 */
        F_mat[3]+F_mat[22]+F_mat[32]+F_mat[14]+F_mat[7],              /* 3 */
        F_mat[4]+F_mat[20]+F_mat[25]+F_mat[15]+F_mat[34]+F_mat[23]+F_mat[9], /*4 */
        F_mat[5]+F_mat[16]+F_mat[7]+F_mat[35]+F_mat[24],       /* 5 */ 
        F_mat[10]+F_mat[21]+F_mat[32]+F_mat[41]+F_mat[36]+F_mat[25],    /* 6 */
        F_mat[11]+F_mat[22]+F_mat[13]+F_mat[38]+F_mat[26],      /* 7 */
        F_mat[12]+F_mat[23]+F_mat[33]+F_mat[19]+F_mat[39]+F_mat[28],    /* 8 */
        F_mat[18]+F_mat[29]+F_mat[14]+F_mat[24]+F_mat[27]             /* 9 */
    };

    int64_t carryValues[10];
    for(int j=0; j<=4; j++){
        carryValues[j] = (h_values[2*j] + (int64_t)(1L << 25)) >> 26;
        h_values[2*j+1] += carryValues[j];
        h_values[2*j] -= carryValues[j] * ((uint64_t) 1L << 26);

        carryValues[j+5] = (h_values[2*j+1] + (int64_t)(1L << 24)) >> 25;
        h_values[(2*j+2)%10] += carryValues[j+5];
        h_values[2*j+1] -= carryValues[j+5] * ((uint64_t) 1L << 25);
    }

    carryValues[0] = h_values[0] + (int64_t)(1L << 25) >> 26;
    h_values[1] += carryValues[0];
    h_values[0] -= carryValues[0] * ((uint64_t) 1L << 26);

    h = h_values;
}