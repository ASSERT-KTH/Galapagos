Below is a variant of the program you provided, with an attempt to reduce the number of variables.


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t f_2[10], f_s[10], h_temp[10], carry9;
    for (int32_t i = 0; i < 10; i++) {
        int64_t fi = f[i], fi_2 = 2 * f[i];
        f_2[i] = fi_2;
        if (i == 5) fi *= 38;
        if (i >= 6 && i <= 8) fi *= 19;
        f_s[i] = fi;
    }

    for (int32_t i = 0; i < 10; i++) {
        int64_t s = (i * 2) < 20 ? f_s[i] : 0, fi_2 = f_2[i];
        for (int32_t j = 0; j <= i; j++) {
            int32_t x = (j == i) && ((i & 1) == 0) ? f[i] : fi_2;
            for (int32_t k = 0; k < 10; k++) {
                s += ((j + k == i) && (i < 2 || k <= j)) ? x * f[k] : 0;
            }
        }
        h_temp[i] = s;
    }

    carry9 = (h_temp[9] + (int64_t)(1<<24)) >> 25;
    h_temp[0] += 19 * carry9;
    h_temp[9] -= carry9 * ((int64_t)1 << 25);
    int64_t carry0 = (h_temp[0] + (int64_t)(1<<25)) >> 26;
    h_temp[1] += carry0;
    h_temp[0] -= carry0 * ((uint64_t)1 << 26);

    for (int32_t i = 0; i < 10; i++) {
        h[i] = (int32_t)h_temp[i];
    }
    }
