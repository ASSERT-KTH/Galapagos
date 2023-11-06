void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_values[] = {f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]};
    int64_t h_values[10], carry_values[10];

    for (int i = 0; i < 10; ++i) {
        int val_1 = 2 * f_values[i];
        int val_2 = 38 * f_values[i];

        int64_t square_val = f_values[i] * (int64_t) f_values[i];
        int64_t sum_of_squares = square_val;

        for (int j = i + 1; j < 10; ++j) {
            sum_of_squares += val_1 * (int64_t) f_values[j];
        }

        if(i % 2 == 0)
            h_values[i] = sum_of_squares + val_1 * (int64_t) f_values[i-1] + val_2;
        else
            h_values[i] = sum_of_squares + val_2;  
    }

    for (int k = 0; k < 9; ++k) {
        carry_values[k] = (h_values[k] + (int64_t)(1L << (25 + (k % 2)))) >> (26 - (k % 2));
        h_values[k + 1] += carry_values[k];
        h_values[k] -= carry_values[k] * ((uint64_t) 1L << (26 - (k % 2)));
    }

    carry_values[9] = (h_values[9] + (int64_t)(1L << 24)) >> 25;
    h_values[0] += carry_values[9] * 19;
    h_values[9] -= carry_values[9] * ((uint64_t) 1L << 25);

    for (int m = 0; m < 10; ++m) {
        carry_values[m] = (h_values[m] + (int64_t)(1L << (25 + (m % 2)))) >> (26 - (m % 2));
        h_values[m] -= carry_values[m] * ((uint64_t) 1L << (26 - (m % 2)));
    }

    for (int n = 0; n < 10; ++n) {
        h[n] = (int32_t) h_values[n]; 
    }    
}