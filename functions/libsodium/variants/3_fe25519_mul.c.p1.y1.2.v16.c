One transformation would be to primarily just re-format the current implementation. First hint is that our g1_19 up to g9_19 and f1_2 to f9_2 assignments, followed the same logic. 

Variations maybe formatted based on user's preference, leveraging the same transformation.

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_values[10];
    int32_t g_values[10];
    int32_t g_values19[9];
    int32_t f_values2[5];
    for (int i=0;i<10;i++) {
        f_values[i] = f[i];
        g_values[i] = g[i];
        if (i < 9) {
            int index = i+1;
            g_values19[i] = 19 * g_values[index];
        }
        if (i%2 != 0) {
            int index = i / 2;
            f_values2[index] = 2 * f[i];
        }
    }

    int64_t temp_vals[100];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if ((i == 1 || i == 3 || i == 5 || i == 7 || i == 9) && (j == 1 || j == 3 || j == 5 || j == 7 || j==9)) 
                temp_vals[10*i+j] = f_values2[i/2] * (int64_t) g_values19[j-1];
            else if ((i == 2 || i == 4 || i == 6 || i == 8) && (j == 8 || j == 9)) 
                temp_vals[10*i+j] = f_values[i] * (int64_t) g_values19[j-1];
            else 
                temp_vals[10*i+j] = f_values[i] * (int64_t) g_values[j];
        }
    }

    int64_t h_vals[10];
    int h_ord[10][10] = { {0, 0, 0, 0, 0, 38, 19, 38, 19, 38},
    {1, 19, 19, 19, 19, 19, 19, 19, 19, 19}, 
    {1, 2, 0, 38, 19, 38, 19, 38, 19, 38},
    {3, 2, 1, 0, 19, 19, 19, 19, 19, 19},
    {1, 2, 2, 2, 0, 38, 19, 38, 19, 38},
    {5, 4, 3, 2, 1, 19, 19, 19, 19, 19},
    {1, 2, 2, 2, 2, 2, 0, 19, 19, 38},
    {7, 6, 5, 4, 3, 2, 1, 0, 19, 19},
    {1, 2, 2, 2, 2, 2, 2, 2, 0,19},
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}};
    for (int i = 0; i < 10; ++i) {
        h_vals[i] = 0;
        for (int j = 0; j < 10; ++j) {
            if (h_ord[j][i] >= 0) h_vals[i] += temp_vals[10*h_ord[j][i]+i];
        }
    }

    int64_t carry[10];
    for (int i = 0; i < 10; i ++) {
        int bit_shift = i % 2 == 0 ? 26 : 25;
        carry[i] = (h_vals[i] + (int64_t)(1L << (bit_shift-1))) >> bit_shift;
        h_vals[(i + 1) % 10] += carry[i];
        h_vals[i] -= carry[i] << bit_shift;
    }

    carry[9] *= 19;
    h_vals[0] += carry[9];
    carry[0] = h_vals[0] >> 26;
    h_vals[0] -= carry[0] << 26;
    h_vals[1] += carry[0];
    
    for (int i=0; i<10;i++) 
        h[i] = h_vals[i];
}
