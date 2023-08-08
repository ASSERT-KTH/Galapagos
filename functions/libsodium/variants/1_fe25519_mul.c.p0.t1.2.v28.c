fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_elementary[] = {f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7], f[8], f[9]};
    int32_t g_elementary[] = {g[0], g[1], g[2], g[3], g[4], g[5], g[6], g[7], g[8], g[9]};

    int32_t h_values[10];
    for (int32_t i = 0; i < 10; i++) {
        int32_t sum = 0;
        for (int32_t j = 0; j <= i; j++) {
            sum += f_elementary[j] * g_elementary[i - j];
        }
        if (i < 9) {
            // contrib of a term at index (j=i+1, k=0) from next row
            sum += 19 * f_elementary[i + 1];
        }
        if (i > 0 && i < 10) {
            // contrib of a term at index (j=0, k=i-1) from prev row
            sum += 2 * f_elementary[i - 1] * g_elementary[0];
        }
        h_values[i] = sum;
    }

    int32_t carry_values[10];
    for (int32_t i = 0; i < 9; i++) {
        carry_values[i] = (h_values[i] + (1 << 25)) >> 26;
        h_values[i] -= carry_values[i] * ((int32_t) 1 << 26);
        h_values[i + 1] += carry_values[i];
    }

    carry_values[9] = (h_values[9] + (1 << 24)) >> 25;
    h_values[9] -= carry_values[9] * ((int32_t) 1 << 25);
    h_values[0] += carry_values[9] * 19;

    int32_t final_carry = (h_values[0] + (1 << 25)) >> 26;
    h_values[0] -= final_carry * ((int32_t) 1 << 26);
    h_values[1] += final_carry;

    for(int32_t i = 0; i < 10; i++){
        h[i] = h_values[i];
    }
}