void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_values[10];
 
    for (int i=0; i<10; ++i)
        f_values[i] = f[i];
    
    int32_t mul_2_values[8] = {2 * f_values[0], 2 * f_values[1], 2 * f_values[2], 2 * f_values[3], 
                    2 * f_values[4], 2 * f_values[5], 2 * f_values[6], 2 * f_values[7]};
    int32_t mul_n_values[5] = {38 * f_values[5], 19 * f_values[6], 38 * f_values[7], 19 * f_values[8], 38 * f_values[9]};

    int64_t temp_values[42];
    
    temp_values[0]  = mul_2_values[0] * (int64_t) f_values[1];
    temp_values[1]  = mul_2_values[0] * (int64_t) f_values[2];
    temp_values[2]  = mul_2_values[0] * (int64_t) f_values[3];
    temp_values[3]  = mul_2_values[0] * (int64_t) f_values[4];
    temp_values[4]  = mul_2_values[0] * (int64_t) f_values[5];
    temp_values[5]  = mul_2_values[0] * (int64_t) f_values[6];
    temp_values[6]  = mul_2_values[0] * (int64_t) f_values[7];
    temp_values[7]  = mul_2_values[0] * (int64_t) f_values[8];
    ...

    // Calculations omitted for brevity 

    // This bit can't be abstracted any further, carry out parts defined separately.
    int64_t carry[10];

    carry[0] = (h_values[0] + (int64_t)(1L << 25)) >> 26;
    carry[4] = (h_values[4] + (int64_t)(1L << 25)) >> 26;

    h_values[1] += carry[0];
    h_values[0] -= carry[0] * ((uint64_t) 1L << 26);
    h_values[5] += carry[4];
    h_values[4] -= carry[4] * ((uint64_t) 1L << 26);
    ...

    for (int i=0; i<10; ++i)
        h[i] = (int32_t) h_values[i];
}