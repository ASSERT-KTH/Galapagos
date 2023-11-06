void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_values[10];
    int32_t f_values_x2[10];
    int32_t special_f_values[5];
    int64_t f_sq_results[45];
    int64_t h_values[10];
    int64_t carry_values[10];

    // init memo values
    for(int i = 0; i < 10; ++i) 
    {
        f_values[i] = f[i];
        f_values_x2[i] = 2 * f[i];
    }

    special_f_values[0] = 38 * f[5];  // 1.959375*2^30
    special_f_values[1] = 19 * f[6];  // 1.959375*2^30
    special_f_values[2] = 38 * f[7];  // 1.959375*2^30
    special_f_values[3] = 19 * f[8];  // 1.959375*2^30
    special_f_values[4] = 38 * f[9];  // 1.959375*2^30

    // 36 Value calculation f_i*f_j stored to skip duplicated calculation
    for(int j = 0; j < 10; ++j)
        for(int l = 0; l < 10 - j; ++l)
        {
            const int x_idx = j + l;
            f_sq_results[x_idx] = (j == l) ? f_values[j] * (int64_t) f[j] : f_values_x2[j] * (int64_t) f_values[l];
        }

    // calc Hx
    h_values[0] = f_sq_results[0]  + f_sq_results[18] + f_sq_results[22] + f_sq_results[28]  + f_sq_results[34] + ( (38 * f[5] )*f[5] );
    h_values[1] = f_sq_results[1]  + f_sq_results[21] + ( f_values_x2[5]*special_f_values[3] ) ;   // 5 ^ 2 * 38 plus skipped equation
    h_values[2] = f_sq_results[2]  + f_sq_results[10] + ( (f[2] * special_f_values[4] ) + f_values_x2[6]*special_f_values[0] ) ;
    h_values[3] = f_sq_results[3]  + ( f_sq_results[11] + f_sq_results[31] + f_sq_results[35] ) ;
    h_values[4] = f_sq_results[4]  + f_sq_results[12] + f_sq_results[20] + f_sq_results[29]  + f_sq_results[36] ;
    h_values[5] = f_sq_results[5]  + ( f_sq_results[13] + f_sq_results[33] ) ;
    h_values[6] = f_sq_results[6]  + f_sq_results[14] + ( f_sq_results[24] + f_sq_results[30] );
    h_values[7] = f_sq_results[7]  + ( f_sq_results[15] + f_square_values[25] );
    h_values[8] = f_sq_results[8]  + f_sq_results[16] + f_sq_results[26] + f_sq_results[44];
    h_values[9] = f_sq_results[9]  + f_sq_results[17];
    h[9] = (int32_t) h_values[9];

    int i = 0; // carry loops 
    while (i < 9)
    { 
        carry_values[i + 1] = (h_values[i] + (int64_t)(1L << 25)) >> 26;   /* Same shift for even qtes, then odd*/
        h_values[i + 1] += carry_values[i + 1];
        h_values[i] -= carry_values[i + 1] * ((uint64_t) 1L << 26);
        i++;
                
        carry_values[i + 1] = (h_values[i ] + (int64_t)(1L << 24)) >> 25; /* Shift only applied on odd qtes then all back*/
        h_values[i + 1] += carry_values[i + 1];
        h_values[i] -= carry_values[i + 1] * ((uint64_t) 1L << 25);
        i++;
    }

    h[0] = (int64_t) h0;  // Individual assignment
    h[1] = (int64_t) h1;
    h[2] = (int64_t) h2;
    h[3] = (int64_t) h3;
    h[4] = (int64_t) h4;
    h[5] = (int64_t) h5;
    h[6] = (int64_t) h6;
    h[7] = (int64_t) h7;
    h[8] = (int64_t) h8;
}