fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t  carry;
    uint128_t r[5], f32[5];

    for (int i = 0; i < 5; i++) f32[i] = (uint128_t) f[i];
    uint128_t f0_2 = f32[0] << 1;
    uint128_t f1_2 = f32[1] << 1;

    r[0] = f32[0] * f32[0] + 38ULL * f32[1] * f32[4] + 38ULL * f32[2] * f32[3];
    r[1] = f0_2 * f32[1] + 38ULL * f32[2] * f32[4] + 19ULL * f32[3] * f32[3];
    r[2] = f0_2 * f32[2] + f32[1] * f32[1] + 38ULL * f32[3] * f32[4];
    r[3] = f0_2 * f32[3] + f1_2 * f32[2] + 19ULL * f32[4] * f32[4];
    r[4] = f0_2 * f32[4] + f1_2 * f32[3] + f32[2] * f32[2];

    for (int i = 0; i < 5; i++) {
        r[i + 1] += ((uint64_t) r[i]) >> 51;
        h[i] = ((uint64_t) r[i]) & mask;
    }
    uint64_t r00 = h[0] + 19ULL * (((uint64_t) r[4]) >> 51);
    h[0] = r00 & mask;
    h[1] += r00 >> 51;
    h[2] += h[1] >> 51;
}
