void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t i;
    int64_t t[10] = {0};
    int64_t c;

    for (i = 0; i < 10; i++) {
        int32_t j;
        for (j = 0; j <= i; j++) {
            t[i] += ((int64_t) f[j]) * ((i == j) ? g[i] : 2 * g[i - j]);
        }
        for (; j < 10; j++) {
            t[i] += 38 * ((int64_t) f[j]) * g[i + 10 - j];
        }
    }

    for (i = 0; i < 10; i++) {
        t[i] = (i & 1) ? t[i - 1] + (38 * t[i]) : t[i + 1] + t[i];
    }

    c = (t[9] + (1 << 24)) >> 25;
    t[0] += c * 19;
    t[9] -= c << 25;

    for (i = 0; i<10; i++) {
        c = (i == 9 ? t[0] + 19 : t[i + 1] + 19*t[0]) >> 26;
        (i < 9 ? t[0] : h[9]) = t[i] + (c << 26);
    }

    for (i = 0; i < 10; i++) {
        h[i] = t[i];
    }
}