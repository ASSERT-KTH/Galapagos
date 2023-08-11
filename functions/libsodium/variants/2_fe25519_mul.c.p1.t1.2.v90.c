fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t carry;
    uint128_t ftemps[5], gtemps[5], r[5], fmultiplied[4];

    for (int i = 0; i < 5; i++) {
        ftemps[i] = (uint128_t)f[i];
        gtemps[i] = (uint128_t)g[i];
    }

    for (int i = 0; i < 4; i++) {
        fmultiplied[i] = 19ULL * ftemps[i+1];
    }

    r[0] = ftemps[0] * gtemps[0] + fmultiplied[0] * gtemps[4] + fmultiplied[1] * gtemps[3] + fmultiplied[2] * gtemps[2] + fmultiplied[3] * gtemps[1];
    r[1] = ftemps[0] * gtemps[1] +  ftemps[1] * gtemps[0] + fmultiplied[1] * gtemps[4] + fmultiplied[2] * gtemps[3] + fmultiplied[3] * gtemps[2];
    r[2] = ftemps[0] * gtemps[2] +  ftemps[1] * gtemps[1] +  ftemps[2] * gtemps[0] + fmultiplied[2] * gtemps[4] + fmultiplied[3] * gtemps[3];
    r[3] = ftemps[0] * gtemps[3] +  ftemps[1] * gtemps[2] +  ftemps[2] * gtemps[1] +  ftemps[3] * gtemps[0] + fmultiplied[3] * gtemps[4];
    r[4] = ftemps[0] * gtemps[4] +  ftemps[1] * gtemps[3] +  ftemps[2] * gtemps[2] +  ftemps[3] * gtemps[1] +  ftemps[4] * gtemps[0];

    for (int i = 0; i < 4; i++) {
        h[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
    }

    h[4] = ((uint64_t) r[4]) & mask;
    carry = (uint64_t) (r[4] >> 51);
    h[0] += carry * 19;

    for (int i = 0; i < 2; i++) {
        carry = h[i] >> 51;
        h[i]    &= mask;
        h[i+1] += carry;
    }
}