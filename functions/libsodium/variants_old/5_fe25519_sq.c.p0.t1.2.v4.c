fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t x0, x1, x2, x3, x4;
    uint128_t y0, y1, y2, y3, y4;
    uint128_t y0_2, y1_2, y1_38, y2_38, y3_38, y3_19, y4_19;
    uint64_t  x00, x01, x02, x03, x04;
    uint64_t  overshoot;

    y0 = (uint128_t) f[0];
    y1 = (uint128_t) f[1];
    y2 = (uint128_t) f[2];
    y3 = (uint128_t) f[3];
    y4 = (uint128_t) f[4];

    y0_2 = y0 << 1;
    y1_2 = y1 << 1;

    y1_38 = 38ULL * y1;
    y2_38 = 38ULL * y2;
    y3_38 = 38ULL * y3;

    y3_19 = 19ULL * y3;
    y4_19 = 19ULL * y4;

    x0 =   y0 * y0 + y1_38 * y4 + y2_38 * y3;
    x1 = y0_2 * y1 + y2_38 * y4 + y3_19 * y3;
    x2 = y0_2 * y2 +    y1 * y1 + y3_38 * y4;
    x3 = y0_2 * y3 +  y1_2 * y2 + y4_19 * y4;
    x4 = y0_2 * y4 +  y1_2 * y3 +     y2 * y2;

    x00      = ((uint64_t) x0) & mask;
    overshoot = (uint64_t) (x0 >> 51);
    x1      += overshoot;
    x01      = ((uint64_t) x1) & mask;
    overshoot = (uint64_t) (x1 >> 51);
    x2      += overshoot;
    x02      = ((uint64_t) x2) & mask;
    overshoot = (uint64_t) (x2 >> 51);
    x3      += overshoot;
    x03      = ((uint64_t) x3) & mask;
    overshoot = (uint64_t) (x3 >> 51);
    x4      += overshoot;
    x04      = ((uint64_t) x4) & mask;
    overshoot = (uint64_t) (x4 >> 51);
    x00     += 19ULL * overshoot;
    overshoot = x00 >> 51;
    x00     &= mask;
    x01     += overshoot;
    overshoot = x01 >> 51;
    x01     &= mask;
    x02     += overshoot;

    h[0] = x00;
    h[1] = x01;
    h[2] = x02;
    h[3] = x03;
    h[4] = x04;
}
