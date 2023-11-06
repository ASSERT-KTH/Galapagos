void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_members[10];
    int32_t f_members_multiplied_by_2[10];
    int32_t f_multipliers[5] = {38, 19, 38, 19, 38};
    int64_t f_products_array[20];
    int64_t h_values[10];
    int32_t carry[10];

    for(int i = 0; i < 10; i++) {
        f_members[i] = f[i];
        if(i < 5) {
            f_members_multiplied_by_2[i] = 2 * f_members[i];
            f_members_multiplied_by_2[i + 5] = 2 * f_members[i + 5];
        }
    }

    for(int i = 0; i < 10; i++) {
        f_products_array[i * 2] = f_members[i] * (int64_t) f_members[i];
        f_products_array[(i * 2) + 1] = f_members_multiplied_by_2[i] * the_pow(2, 5 * (i % 2)) * (int64_t) f_members[(i + 1) % 10];

        if(i >= 5) {
            f_products_array[i * 2] *=  (int64_t) f_multipliers[i - 5];
            f_products_array[(i * 2) + 1] *=  (int64_t) f_multipliers[(i - 5) + 1];
        }
    }

    for(int i = 0; i < 5; i++) {
        h_values[i * 2] = f_products_array[i * 4] + f_products_array[(i * 4) + 2] + f_products_array[(i * 4) + 5];
        h_values[(i * 2) + 1] = f_products_array[(i * 4) + 1] + f_products_array[(i * 4) + 3] + f_products_array[(i * 4) + 6];
    }

    h_values[9] = f[0] * 2 * (int64_t) f[9];
    h_values[0] += 19 * (((h_values[9] >> 24) + (int64_t)(1L << 24)) >> 25);
    h_values[9] -= (((h_values[9] >> 24) + (int64_t)(1L << 24)) >> 25) * ((uint64_t) 1L << 25);

    for(int i = 0; i < 10; i++) {
        carry[i] = (h_values[i] + (int64_t)(1L << ((i % 2 == 0) ? 25 : 24))) >> ((i % 2 == 0) ? 26 : 25);
        if(i != 9)
            h_values[i + 1] += carry[i];
        h_values[i] -= carry[i] << ((i % 2 == 0) ? 26 : 25);
    }

    carry[0] = ((h_values[0] + (int64_t)(1L << 25)) >> 26);
    h_values[1] += carry[0];
    h_values[0] -= carry[0] * ((uint64_t) 1L << 26);

    for(int i = 0; i < 10; i++) {
        h[i] = (int32_t) h_values[i];
    }
}