Variant 1:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f[5], g[5];

    for (int i = 0; i < 5; i++) {
        f[i] = (uint128_t)f[i];
        g[i] = (uint128_t)g[i];
    }

    uint128_t f19[4] = {19ULL * f[1], 19ULL * f[2], 19ULL * f[3], 19ULL * f[4]};
    uint128_t r[5] = {
        f[0] * g[0] + f19[0] * g[4] + f19[1] * g[3] + f19[2] * g[2] + f19[3] * g[1],
        f[0] * g[1] + f[1] * g[0] + f19[1] * g[4] + f19[2] * g[3] + f19[3] * g[2],
        f[0] * g[2] + f[1] * g[1] + f[2] * g[0] + f19[2] * g[4] + f19[3] * g[3],
        f[0] * g[3] + f[1] * g[2] + f[2] * g[1] + f[3] * g[0] + f19[3] * g[4],
        f[0] * g[4] + f[1] * g[3] + f[2] * g[2] + f[3] * g[1] + f[4] * g[0]
    };

    uint64_t carry;
    for (int i = 0; i < 5; i++) {
        (uint64_t)r[i] &= mask;
        carry = (uint64_t)(r[i] >> 51);
        r[(i + 1) % 5] += carry;
    }

    r[0] += 19ULL * ((uint64_t)(r[4] >> 51));

    for (int i = 0; i < 3; i++) {
        carry = r[i] >> 51;
        r[i] &= mask;
        r[i + 1] += carry;
    }

    for (int i = 0; i < 5; i++) h[i] = (uint64_t)r[i];
}


Variant 2:

fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) {
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t fVals[5], gVals[5], fg19Vals[4], rVals[5], carry;

    for(int i = 0; i < 5; i++) {
        fVals[i] = f[i];
        gVals[i] = g[i];
        if(i < 4 ) {
            fg19Vals[i] = 19ULL * fVals[i+1];
        }
    }

    rVals[0] = fVals[0] * gVals[0] + fg19Vals[0] * gVals[4] + fg19Vals[1] * gVals[3] + fg19Vals[2] * gVals[2] + fg19Vals[3] * gVals[1];

    for (int i = 1; i < 5; ++i) {
        rVals[i] = fVals[0] * gVals[i] + fVals[i] * gVals[0] + (i < 4 ? (fg19Vals[i-1] * gVals[4] + fg19Vals[i] * gVals[3] + fg19Vals[i+1] * gVals[2]) : 0);
    }

    for(int k = 0; k < 2; k++){
        for(int l = 0; l < 5; l++) {
            (uint64_t)rVals[l] &= mask;
            carry  = (uint64_t) (rVals[l] >> 51);
            rVals[(l + 1)%5] += carry;
        }
    }

    rVals[0] += 19ULL * ((uint64_t)(rVals[4] >> 51));

    for (int j = 0; j < 3; ++j) {
        carry  = rVals[j] >> 51;
        rVals[j] &= mask;
        rVals[j+1] += carry;
    }

    for(int m = 0; m < 5; m++) {
        h[m] = (uint64_t)rVals[m];
    }
}
