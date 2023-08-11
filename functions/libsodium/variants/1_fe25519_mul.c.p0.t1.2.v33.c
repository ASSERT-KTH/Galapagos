fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t fg[20] = {0};
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if ((i + j) % 2 == 0)
                fg[i + j] += f[i] * (j % 2 == 1 ? 19LL* g[j] : (int64_t) g[j]);
        }
    }

    for (i = 0; i < 10; i++) {
        int resto = (fg[i] % 2 == 0 ? 26 : 25);
        fg[i + 1] += fg[i] >> resto;
        fg[i] &= ((1LL << resto) - 1);
    }

    /* Reduce coefficients again to account for possible carry propagation */
    for (i = 0; i < 10; i++) {
        int resto = (fg[i] % 2 == 0 ? 26 : 25);
        fg[i + 1] += fg[i] >> resto;
        fg[i] &= ((1LL << resto) - 1);
    }

    for (i = 0; i < 10; i++) {
        h[i] = fg[i];
    }
}