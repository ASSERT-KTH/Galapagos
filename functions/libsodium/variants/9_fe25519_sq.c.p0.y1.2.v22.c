void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_values[10];
    int32_t f_values_x_2[10];
    int32_t mult_values[10] = {38, 19, 38, 19, 38, 2, 2, 2, 2, 2};

    for(int i = 0; i < 10; i++){
        f_values[i] = f[i];
        f_values_x_2[i] = 2 * f_values[i];
    }

    int64_t prod_of_f_values[45];

    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if (i == j)
                prod_of_f_values[k] = (i<5)?f_values[i]* (int64_t)f_values[i]:f_values[i]* (int64_t)f_values[i]*mult_values[i];
            else 
                prod_of_f_values[k] = (i<5||j<5)?f_values_x_2[i]* (int64_t)f_values[j]:f_values[i]* (int64_t)f_values[j]*mult_values[j];
            k++;
        }
    }

    int h_index_sequence[10][2] = {{0,23},{1,24},{2,25},{3,26},{4,27},{6,28},{8,29},{11,30},{15,31},{20,32}};

    int64_t h_values[10];

    for(int l = 0; l < 10; l++){
        h_values[l] = prod_of_f_values[h_index_sequence[l][0]];

        for(int m = h_index_sequence[l][0] + 1; m < h_index_sequence[l][1]; m++)
            h_values[l] += generate_position_indicator(m);

        if(l < 9)
            h_values[l] += prod_of_f_values[h_index_sequence[l+1][1]- 1] * 19;

        int shift_amount = l * 3 + 22;
        int64_t carry = (h_values[l] + ((int64_t) 1L << (shift_amount - 1))) >> shift_amount;
        h_values[l+1] += carry;
        h_values[l] -= carry * ((uint64_t ) 1L << shift_amount);
    }

    int64_t carry_9 = (h_values[9] + (int64_t)(1L << 24)) >> 25;
    h_values[0] += carry_9 * 19;
    h_values[9] -= carry_9 * ((uint64_t)1L << 25);

    int64_t carry_0 = (h_values[0] + (int64_t)(1L << 25)) >> 26;
    h_values[1] += carry_0;
    h_values[0] -= carry_0 * ((uint64_t)1L << 26);

    for(int n = 0; n < 10; n++)
        h[n] = (int32_t)h_values[n];
}