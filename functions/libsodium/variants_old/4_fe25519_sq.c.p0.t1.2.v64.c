fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_element[10];
    int32_t double_f_element[8];
    int32_t adjusted_f_element[5];
    int64_t sq_f_element[45];
    int64_t result_h[10];
    int64_t carry[10];

    for (int i = 0; i < 10; i++) {
        f_element[i] = f[i];
    }

    for (int i = 0; i < 5; i++) {
        double_f_element[i] = 2 * f_element[i];
        adjusted_f_element[i] = 38 * f_element[i+5];
    }

    for (int i = 5; i < 8; i++) {
        double_f_element[i] = 2 * f_element[i];
        adjusted_f_element[i] = 19 * f_element[i+3];
    }

    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if (i == j) {
                sq_f_element[index] = f_element[i] * (int64_t)f_element[j];
            }
            else if (j - i == 1 && i % 2 == 0) {
                sq_f_element[index] = double_f_element[i] * (int64_t)f_element[j];
            }
            else if (j - i == 1 && i % 2 == 1) {
                sq_f_element[index] = double_f_element[i] * (int64_t)f_element[j];
            }
            else if (j > 4) {
                sq_f_element[index] = double_f_element[i] * (int64_t)adjusted_f_element[j-5];
            }
            else {
                sq_f_element[index] = double_f_element[i] * (int64_t)f_element[j];
            }
            index++;
        }
    }

    result_h[0] = sq_f_element[0] + sq_f_element[14] + sq_f_element[19] + sq_f_element[24] + sq_f_element[29] + sq_f_element[9];
    result_h[1] = sq_f_element[1] + sq_f_element[20] + sq_f_element[25] + sq_f_element[30] + sq_f_element[10];
    result_h[2] = sq_f_element[2] + sq_f_element[6] + sq_f_element[26] + sq_f_element[31] + sq_f_element[15] + sq_f_element[11];
    result_h[3] = sq_f_element[3] + sq_f_element[7] + sq_f_element[32] + sq_f_element[16] + sq_f_element[12];
    result_h[4] = sq_f_element[4] + sq_f_element[8] + sq_f_element[13] + sq_f_element[33] + sq_f_element[21] + sq_f_element[17];
    result_h[5] = sq_f_element[5] + sq_f_element[18] + sq_f_element[23] + sq_f_element[34] + sq_f_element[22];
    result_h[6] = sq_f_element[27] + sq_f_element[35] + sq_f_element[36] + sq_f_element[28] + sq_f_element[23] + sq_f_element[19]
            + sq_f_element[24];
    result_h[7] = sq_f_element[37] + sq_f_element[38] + sq_f_element[25] + sq_f_element[20] + sq_f_element[21];
    result_h[8] = sq_f_element[39] + sq_f_element[40] + sq_f_element[41] + sq_f_element[5] + sq_f_element[22]
            + sq_f_element[26] + sq_f_element[15] + sq_f_element[16];
    result_h[9] = sq_f_element[42] + sq_f_element[43] + sq_f_element[27] + sq_f_element[28] + sq_f_element[17];

}
