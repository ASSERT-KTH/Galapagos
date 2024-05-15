modp_mkgm2(uint32_t *gm, uint32_t *igm, unsigned logn,
           uint32_t g, uint32_t p, uint32_t p0i) {
    size_t u, n;
    unsigned k;
    uint32_t ig, x1, x2, R2;

    n = (size_t)1 << logn;

    /*
     * We want g such that g^(2N) = 1 mod p, but the provided
     * generator has order 2048. We must square it a few times.
     */
    R2 = modp_R2(p, p0i);
    g = modp_montymul(g, R2, p, p0i);
    for (k = logn; k < 10; k ++) {
        g = modp_montymul(g, g, p, p0i);
    }

    ig = modp_div(R2, g, p, p0i, modp_R(p));
    k = 10 - logn;
    x1 = x2 = modp_R(p);
    for (u = 0; u < n; u ++) {
        size_t v;

        v = REV10[u << k];
        gm[v] = x1;
        igm[v] = x2;
        x1 = modp_montymul(x1, g, p, p0i);
        x2 = modp_montymul(x2, ig, p, p0i);
    }
}