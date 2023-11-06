fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t w0, w1, w2, w3, w4;
    uint128_t x0, x1, x2, x3, x4;
    uint128_t x1_19, x2_19, x3_19, x4_19;
    uint128_t y0, y1, y2, y3, y4;
    uint64_t  w00, w01, w02, w03, w04;
    uint64_t  offset;

    x0 = (uint128_t) f[0];
    x1 = (uint128_t) f[1];
    x2 = (uint128_t) f[2];
    x3 = (uint128_t) f[3];
    x4 = (uint128_t) f[4];

    y0 = (uint128_t) g[0];
    y1 = (uint128_t) g[1];
    y2 = (uint128_t) g[2];
    y3 = (uint128_t) g[3];
    y4 = (uint128_t) g[4];

    x1_19 = 19ULL * x1;
    x2_19 = 19ULL * x2;
    x3_19 = 19ULL * x3;
    x4_19 = 19ULL * x4;

    w0 = x0 * y0 + x1_19 * y4 + x2_19 * y3 + x3_19 * y2 + x4_19* y1;
    w1 = x0 * y1 +    x1 * y0 + x2_19 * y4 + x3_19 * y3 + x4_19 * y2;
    w2 = x0 * y2 +    x1 * y1 +    x2 * y0 + x3_19 * y4 + x4_19 * y3;
    w3 = x0 * y3 +    x1 * y2 +    x2 * y1 +    x3 * y0 + x4_19 * y4;
    w4 = x0 * y4 +    x1 * y3 +    x2 * y2 +    x3 * y1 +    x4 * y0;

    w00    = ((uint64_t) w0) & mask;
    offset  = (uint64_t) (w0 >> 51);
    w1    += offset;
    w01    = ((uint64_t) w1) & mask;
    offset  = (uint64_t) (w1 >> 51);
    w2    += offset;
    w02    = ((uint64_t) w2) & mask;
    offset  = (uint64_t) (w2 >> 51);
    w3    += offset;
    w03    = ((uint64_t) w3) & mask;
    offset  = (uint64_t) (w3 >> 51);
    w4    += offset;
    w04    = ((uint64_t) w4) & mask;
    offset  = (uint64_t) (w4 >> 51);
    w00   += 19ULL * offset;
    offset  = w00 >> 51;
    w00   &= mask;
    w01   += offset;
    offset  = w01 >> 51;
    w01   &= mask;
    w02   += offset;

    h[0] = w00;
    h[1] = w01;
    h[2] = w02;
    h[3] = w03;
    h[4] = w04;
}