fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint64_t r[5];
    const uint64_t mask = 0x7ffffffffffffULL;

    __uint128_t g0 = ((__uint128_t) g[0]);
    __uint128_t g1 = ((__uint128_t) g[1]);
    __uint128_t g2 = ((__uint128_t) g[2]);
    __uint128_t g3 = ((__uint128_t) g[3]);
    __uint128_t g4 = ((__uint128_t) g[4]);

    __uint128_t f0 = ((__uint128_t)f[0]);
    __uint128_t f1 = ((__uint128_t)f[1]);
    __uint128_t f2 = ((__uint128_t)f[2]);
    __uint128_t f3 = ((__uint128_t)f[3]);
    __uint128_t f4 = ((__uint128_t)f[4]);

    __uint128_t product = f0 * g0\n +
        19ULL * ((f1 * g4) + (f2 * g3) + (f3 * g2) + (f4 * g1));
    r[0] = product & mask;
    product = product >> 51;

    product += f0 * g1\n + f1 * g0\n + 
         19ULL * ((f2 * g4) + (f3 * g3) + (f4 * g2));
    r[1] = product & mask;
    product = product >> 51;

    product += f0 * g2\n + f1 * g1\n + f2 * g0\n + 
        19ULL * ((f3 * g4) + (f4 * g3));
    r[2] = product & mask;
    product = product >> 51;

    product += f0 * g3\n + f1 * g2\n + f2 * g1\n + f3 * g0\n + 
    19ULL * (f4 * g4);
    r[3] = product & mask;
    product = product >> 51;

    product += r[0] + ((f0 * g4\n + f1 * g3\n + f2 * g2\n + f3 * g1 + f4 * g0) - product);
    r[4] = product & mask;
    product = product >> 51;

    r[0] += 19ULL * (product);

    h[0] = r[0];
    h[1] = r[1];
    h[2] = r[2];
    h[3] = r[3];
    h[4] = r[4];  
}