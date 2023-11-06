void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_values[10];
    int32_t f_values_x2[10];
    int32_t f_values_scaled[5];
    int64_t f_x_f[100];
    int64_t h_values[10];
    int64_t carry[10];

    for (size_t i = 0; i < 10; ++i) f_values[i] = f[i];

    for (size_t i = 0; i < 10; ++i) f_values_x2[i] = 2 * f_values[i];

    f_values_scaled[0] = 38 * f_values[5];
    f_values_scaled[1] = 19 * f_values[6];
    f_values_scaled[2] = 38 * f_values[7];
    f_values_scaled[3] = 19 * f_values[8];
    f_values_scaled[4] = 38 * f_values[9];

    for (size_t i = 0; i < 100; ++i) f_x_f[i] = 0;
  
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            if ((j < 5) && ((i + j) % 2 == 0))
                f_x_f[i * 10 + j] += f_values[i] * f_values_x2[j];  
            else if (j < 5)
                f_x_f[i * 10 + j] += f_values_x2[i] * f_values[j];  
            else
                f_x_f[i * 10 + j] += f_values[i] * f_values_scaled[j - 5];  
        }
    }
    
    for (size_t i = 0; i < 10; ++i) {
        h_values[i] = f_x_f[10 * i];
        for (size_t j = 1; j < 10; ++j) {
            h_values[i] += f_x_f[10 * i + j];
        }
    }

    for (size_t i = 0; i < 10; ++i) {
        carry[(i + 1) % 10] = (h_values[i] + (int64_t)(1L << (i % 2 == 0 ? 25 : 24))) >> (i % 2 == 0 ? 26 : 25);
        h_values[(i + 1) % 10] += carry[(i + 1) % 10];
        h_values[i] -= carry[(i + 1) % 10] * (i % 2 == 0 ? ((uint64_t) 1L << 26) : ((uint64_t) 1L << 25));
    }

    carry[0] = (h_values[0] + (int64_t)(1L << 25)) >> 26;
    h_values[1] += carry[0];
    h_values[0] -= carry[0] * ((uint64_t) 1L << 26);

    for (size_t i = 0; i < 10; ++i) h[i] = (int32_t) h_values[i];
}