fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_vals[10];
    int32_t g_vals[10];
    int32_t scaled_g_vals[10];
    int32_t doubled_f_vals[5];
    int64_t fg_vals[10][10];
    int64_t result[10];
    int64_t carries[10];


    for (int i = 0; i < 10; ++i) {
        f_vals[i] = f[i];
        g_vals[i] = g[i];
    }

    for (int i = 1; i < 10; i += 2)
        doubled_f_vals[i / 2] = 2 * f_vals[i];

    for (int i = 1; i < 10; ++i)
        scaled_g_vals[i] = 19 * g_vals[i];

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            fg_vals[i][j] = (int64_t)f_vals[i] * (int64_t)(i % 2 == 0 ? g_vals[j] : scaled_g_vals[j]);

    for (int i = 0; i < 10; ++i) {
        result[i] = 0;
        for (int j = 0; j < 10; ++j)
            result[i] += fg_vals[i][j];
        
        carries[i] = (result[i] + (int64_t)(1L << ((i < 5) ? 25 : 24))) >> ((i < 5) ? 26 : 25);
    }

    result[1] += carries[0];
    result[0] -= carries[0] * ((uint64_t) 1L << 26);
    result[5] += carries[4];
    result[4] -= carries[4] * ((uint64_t) 1L << 26);
    
    for (int i = 1; i < 5; ++i) {
        result[i + 1] += carries[i];
        result[i] -= carries[i] * ((uint64_t) 1L << 25);
        result[i + 6] += carries[i + 4];
        result[i + 4] -= carries[i + 4] * ((uint64_t) 1L << 25);
    }

    carries[9] = (result[9] + (int64_t)(1L << 24)) >> 25;
    result[0] += carries[9] * 19;
    result[9] -= carries[9] * ((uint64_t) 1L << 25);

    carries[0] = (result[0] + (int64_t)(1L << 25)) >> 26;
    result[1] += carries[0];
    result[0] -= carries[0] * ((uint64_t) 1L << 26);

    for (int i = 0; i < 10; ++i)
        h[i] = (int32_t) result[i];
}
