void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    int32_t i, j;

    int64_t carry[10];
    int64_t hBuffer[10];
    int64_t fInput[10];
    int64_t g_muli;

    memset(hBuffer, 0, 10 * sizeof(int64_t));

    /* Convert input int32_t array to int64_t array */
    for (i = 0; i < 10; i++)
        fInput[i] = f[i];

    for (i = 0; i < 10; i++) {
        g_muli = (i == 1 || i == 3 || i == 5 || i == 7 || i == 9) ? 19 * g[i] : g[i];
        for (j = 0; j < 10; j++)
            hBuffer[(i + j) % 10] += fInput[j] * g_muli;
    }

    for (i = 0; i < 9; i++) {
        carry[i + 1] = (hBuffer[i] + (1 << 24) ) >> 25;
        hBuffer[(i + 10) % 10] += carry[i + 1] * 19;
        hBuffer[i] -= carry[i + 1] << 25;
    }

    carry[0] = (hBuffer[9] + (1 << 24) ) >> 25;
    hBuffer[0] += carry[0] * 19;
    hBuffer[9] -= carry[0] << 25;

    for (i = 0; i < 10; i++)
        h[i] = hBuffer[i];
}