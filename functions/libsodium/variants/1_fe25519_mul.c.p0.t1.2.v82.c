fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_elements[10];
    int32_t g_elements[10];
    int32_t g19_elements[10];
    int32_t f2_elements[6];
    int64_t fg_elements[100];
    int64_t h_elements[10];

    for (int i = 0; i < 10; i++) {
        f_elements[i] = f[i];
        g_elements[i] = g[i];
        if (i % 2 == 1) {
            f2_elements[i / 2] = 2 * f[i];
        }
        if (i != 0) {
            g19_elements[i] = 19 * g[i];
        }
    }

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i < 5 && j == 2 * i + 1) {
                fg_elements[10 * i + j] = f2_elements[i] * (int64_t)g19_elements[(j + 10) / 2];
            } else if ((i + j) % 2 == 0) {
                fg_elements[10 * i + j] = f_elements[i] * (int64_t)g_elements[j];
            } else {
                fg_elements[10 * i + j] = f_elements[i] * (int64_t)g19_elements[j];
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        h_elements[i] = 0;
        for (int j = 0; j <= 9; j++) {
            h_elements[i] += fg_elements[10 * ((i + j) % 10) + j];
        }
    }

    int64_t overflow;
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            overflow = (h_elements[i] + (int64_t)(1L<<25)) >> 26;
        } else {
            overflow = (h_elements[i] + (int64_t)(1L<<24)) >> 25;
        }
        h_elements[(i + 1) % 10] += overflow;
        h_elements[i] -= overflow * ((i % 2 == 0) ? ((int64_t) 1L << 26) : ((int64_t) 1L << 25));
    }

    for (int i = 0; i < 10; i++) {
        h[i] = (int32_t)h_elements[i];
    }
}