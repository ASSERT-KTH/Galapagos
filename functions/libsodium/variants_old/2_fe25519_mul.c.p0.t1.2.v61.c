fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t fValues[5];
    uint128_t gValues[5];
    uint64_t  rValues[5];
    uint64_t  carry;

    for(int i = 0; i < 5; i++) {
        fValues[i] = (uint128_t) f[i];
        gValues[i] = (uint128_t) g[i];
    }

    uint128_t fMult19[5] = {fValues[0], 19ULL * fValues[1], 19ULL * fValues[2], 19ULL * fValues[3], 19ULL * fValues[4]};

    r0 = fMult19[0] * gValues[0] + fMult19[1] * gValues[4] + fMult19[2] * gValues[3] + fMult19[3] * gValues[2] + fMult19[4] * gValues[1];
    r1 = fValues[0] * gValues[1] +    fValues[1] * gValues[0] + fMult19[2] * gValues[4] + fMult19[3] * gValues[3] + fMult19[4] * gValues[2];
    r2 = fValues[0] * gValues[2] +    fValues[1] * gValues[1] +   fValues[2] * gValues[0] + fMult19[3] * gValues[4] + fMult19[4] * gValues[3];
    r3 = fValues[0] * gValues[3] +    fValues[1] * gValues[2] +   fValues[2] * gValues[1] +  fValues[3] * gValues[0] + fMult19[4] * gValues[4];
    r4 = fValues[0] * gValues[4] +    fValues[1] * gValues[3] +   fValues[2] * gValues[2] +  fValues[3] * gValues[1] +  fValues[4] * gValues[0];

    uint128_t rValuesLong[5] = {r0, r1, r2, r3, r4};
    
    for(int i = 0; i < 4; i++) {
        rValues[i]    = ((uint64_t) rValuesLong[i]) & mask;
        carry  = (uint64_t) (rValuesLong[i] >> 51);
        rValuesLong[i+1] += carry;
    }
    rValues[4]    = ((uint64_t) rValuesLong[4]) & mask;
    carry  = (uint64_t) (rValuesLong[4] >> 51);
    rValues[0] += 19ULL * carry;
    for(int i = 0; i < 2; i++) {
        carry  = rValues[i] >> 51;
        rValues[i]   &= mask;
        rValues[i+1] += carry;
    }

    for(int i = 0; i < 5; i++)
        h[i] = rValues[i];
}