fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t standalone_mask = 0x7ffffffffffffULL;
    uint128_t a, b, c, d, e;
    uint128_t fa, fb, fc, fd, fe;
    uint128_t f2x, f3x, f4x, f5x;
    uint128_t gx, gy, gz, ga, gh;
    uint64_t  r1x, r1y, r1z, r1a, r1b;
    uint64_t  rollOverValue;

    fa = (uint128_t) f[0];
    fb = (uint128_t) f[1];
    fc = (uint128_t) f[2];
    fd = (uint128_t) f[3];
    fe = (uint128_t) f[4];

    gx = (uint128_t) g[0];
    gy = (uint128_t) g[1];
    gz = (uint128_t) g[2];
    ga = (uint128_t) g[3];
    gh = (uint128_t) g[4];

    f2x = 19ULL * fb;
    f3x = 19ULL * fc;
    f4x = 19ULL * fd;
    f5x = 19ULL * fe;

    a = fa * gx + f2x * gh + f3x * ga + f4x * gz + f5x * gy;
    b = fa * gy +    fb * gx + f3x * gh + f4x * ga + f5x * gz;
    c = fa * gz +    fb * gy +    fc * gx + f4x * gh + f5x * ga;
    d = fa * ga +    fb * gz +    fc * gy +    fd * gx + f5x * gh;
    e = fa * gh +    fb * ga +    fc * gz +    fd * gy +    fe * gx;

    r1x   = ((uint64_t) a) & standalone_mask;
    rollOverValue = (uint64_t) (a >> 51);
    b += rollOverValue;
    r1y = ((uint64_t) b) & standalone_mask;
    rollOverValue = (uint64_t) (b >> 51);
    c += rollOverValue;
    r1z = ((uint64_t) c) & standalone_mask;
    rollOverValue = (uint64_t) (c >> 51);
    d += rollOverValue;
    r1a = ((uint64_t) d) & standalone_mask;
    rollOverValue = (uint64_t) (d >> 51);
    e += rollOverValue;
    r1b = ((uint64_t) e) & standalone_mask;
    rollOverValue = (uint64_t) (e >> 51);
    r1x += 19ULL * rollOverValue;
    rollOverValue = r1x >> 51;
    r1x &= standalone_mask;
    r1y += rollOverValue;
    rollOverValue = r1y >> 51;
    r1y &= standalone_mask;
    r1z += rollOverValue;

    h[0] = r1x;
    h[1] = r1y;
    h[2] = r1z;
    h[3] = r1a;
    h[4] = r1b;
}