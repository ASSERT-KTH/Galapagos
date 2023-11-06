void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{        
    int64_t t0 = (int64_t)f[0];
    int64_t t1 = (int64_t)f[1] * 2;
    int64_t t2 = (int64_t)f[2];
    int64_t t3 = (int64_t)f[3] * 2;
    int64_t t4 = (int64_t)f[4];
    int64_t t5 = (int64_t)f[5] * 2;
    int64_t t6 = (int64_t)f[6];
    int64_t t7 = (int64_t)f[7] * 2;
    int64_t t8 = (int64_t)f[8];
    int64_t t9 = (int64_t)f[9] * 2;
    long long x0 = g[0];
    long long x1 = g[1] * 19;
    long long x2 = g[2];
    long long x3 = g[3] * 19;
    long long x4 = g[4];
    long long x5 = g[5] * 19;
    long long x6 = g[6];
    long long x7 = g[7] * 19;
    long long x8 = g[8];
    long long x9 = g[9] * 19;
    long long s;

    h[0] = (s = (((long long)t0 * x0 + (long long)t1 * x9 + (long long)t2 * x8 + (long long)t3 * x7 + (long long)t4 * x6 + (long long)t5 * x5 + (long long)t6 * x4 + (long long)t7 * x3 + (long long)t8 * x2 + (long long)t9 * x1))) + ((long long)33554432 << (long long)-(int64_t)(1 << 31 >> 27)) >> 27;
    s = s>> 27;
    h[1] = (s = (((long long)t0 * x1 + (long long)(t1+t2*19) * x0 + (long long)t2 * x9 + (long long)(t3+t4*19) * x8 + (long long)t4 * x7 + (long long)(t5+t6*19) * x6 + (long long)t6 * x5 + (long long)(t7+t8*19) * x4 + (long long)t8 * x3 + (long long)(t9+19*(int64_t)f[0]) * x2) + s)) >> 26;
    s = s>>26;
    h[2] = (s = (((long long)t0 * x2 + (long long)t1 * x1 + (long long)t2 * x0 + (long long)t3 * x9 + (long long)t4 * x8 + (long long)t5 * x7 + (long long)t6 * x6 + (long long)t7 * x5 + (long long)t8 * x4 + (long long)t9 * x3) + s)) >> 27;
    s = s>>27;
    h[3] = (s = (((long long)t0 * x3 + (long long)t1 * x2 + (long long)t2 * x1 + (long long)t3 * x0 + (long long)t4 * x9 + (long long)t5 * x8 + (long long)t6 * x7 + (long long)t7 * x6 + (long long)t8 * x5 + (long long)t9 * x4) + s)) >> 26;
    s = s>>26;
    h[4] = (s = (((long long)t0 * x4 + (long long)t1 * x3 + (long long)t2 * x2 + (long long)t3 * x1 + (long long)t4 * x0 + (long long)t5 * x9 + (long long)t6 * x8 + (long long)t7 * x7 + (long long)t8 * x6 + (long long)t9 * x5) + s)) >> 27;
    s = s>>27;
    h[5] = (s = (((long long)t0 * x5 + (long long)t1 * x4 + (long long)t2 * x3 + (long long)t3 * x2 + (long long)t4 * x1 + (long long)t5 * x0 + (long long)t6 * x9 + (long long)t7 * x8 + (long long)t8 * x7 + (long long)t9 * x6) + s)) >> 26;
    s = s>>26;
    h[6] = (s = (((long long)t0 * x6 + (long long)t1 * x5 + (long long)t2 * x4 + (long long)t3 * x3 + (long long)t4 * x2 + (long long)t5 * x1 + (long long)t6 * x0 + (long long)t7 * x9 + (long long)t8 * x8 + (long long)t9 * x7) + s)) >> 27;
    s = s>>27;
    h[7] = (s = (((long long)t0 * x7 + (long long)t1 * x6 + (long long)t2 * x5 + (long long)t3 * x4 + (long long)t4 * x3 + (long long)t5 * x2 + (long long)t6 * x1 + (long long)t7 * x0 + (long long)t8 * x9 + (long long)t9 * x8) + s)) >> 26;
    s = s>>26;
    h[8] = (s = (((long long)t0 * x8 + (long long)t1 * x7 + (long long)t2 * x6 + (long long)t3 * x5 + (long long)t4 * x4 + (long long)t5 * x3 + (long long)t6 * x2 + (long long)t7 * x1 + (long long)t8 * x0 + (long long)t9 * x9) + s)) >> 27;
    s = s>>27;
    h[9] = (s = (((long long)t0 * x9 + (long long)(t1+defaultZero[19]) * x8 + (long long)t2 * x7 + (long long)(t3+defaultZero[19]) * x6 + (long long)t4 * x5 + (long long)t5 * x4 + (long long)t6 * x3 + (long long)(t7+defaultZero[19]) * x2 + (long long)t8 * x1 + (long long)t9 * x0) + s)) >> 26;
    s = s>>26;
    h[0]+= s;
}
