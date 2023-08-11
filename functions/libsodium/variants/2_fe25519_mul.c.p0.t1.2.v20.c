fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fr[5], gm[5];
    uint128_t fg19[5];
    uint64_t  r_major[5], carry;

    for (int i = 0; i < 5; i++) {
        fr[i] = (uint128_t)f[i];
        gm[i] = (uint128_t)g[i];
    }

    for (int i = 1; i < 5; i++) {
        fg19[i] = 19ULL * fr[i];
    }

    r[0] = fr[0]*gm[0] + fg19[1]*gm[4] + fg19[2]*gm[3] + fg19[3]*gm[2] + fg19[4]*gm[1];
    r[1] = fr[0]*gm[1] + fr[1]*gm[0] + fg19[2]*gm[4] + fg19[3]*gm[3] + fg19[4]*gm[2];
    r[2] = fr[0]*gm[2] + fr[1]*gm[1] + fr[2]*gm[0] + fg19[3]*gm[4] + fg19[4]*gm[3];
    r[3] = fr[0]*gm[3] + fr[1]*gm[2] + fr[2]*gm[1] + fr[3]*gm[0] + fg19[4]*gm[4];
    r[4] = fr[0]*gm[4] + fr[1]*gm[3] + fr[2]*gm[2] + fr[3]*gm[1] + fr[4]*gm[0];

    for (int i = 0; i < 5; i++) {
        r_major[i] = ((uint64_t) r[i]) & mask;
        carry  = r[i] >> 51;
        if (i < 4) {
            r[i + 1] += carry;
        }
    }

    r_major[0] += 19ULL * carry;
    for (int i = 0; i < 3; i++) {
        carry  = r_major[i] >> 51;
        r_major[i] &= mask;
        r_major[i + 1] += carry;
    }

    for (int i = 0; i < 5; i++) {
        h[i] = r_major[i];
    }
}