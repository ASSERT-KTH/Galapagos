void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t carry;
    uint128_t gVals[5];
    uint128_t fVals[5];
    uint128_t term1[5];
    uint128_t fg[5];
    uint64_t  finalValues[5];

    for(int i = 0; i < 5; i++) {
        fVals[i] = (uint128_t) f[i];
        gVals[i] = (uint128_t) g[i];
    }

    term1[0] =  19ULL * fVals[0];
    term1[1] =  19ULL * fVals[1];
    term1[2] =  19ULL * fVals[2];
    term1[3] =  19ULL * fVals[3];
    term1[4] =  19ULL * fVals[4];

    fg[0] = fVals[0] * gVals[0] + term1[1] * gVals[4] + term1[2] * gVals[3] + term1[3] * gVals[2] + term1[4] * gVals[1];
    fg[1] = fVals[0] * gVals[1] + fVals[1] * gVals[0] + term1[2] * gVals[4] + term1[3] * gVals[3] + term1[4] * gVals[2];
    fg[2] = fVals[0] * gVals[2] + fVals[1] * gVals[1] + fVals[2] * gVals[0] + term1[3] * gVals[4] + term1[4] * gVals[3];
    fg[3] = fVals[0] * gVals[3] + fVals[1] * gVals[2] + fVals[2] * gVals[1] + fVals[3] * gVals[0] + term1[4] * gVals[4];
    fg[4] = fVals[0] * gVals[4] + fVals[1] * gVals[3] + fVals[2] * gVals[2] + fVals[3] * gVals[1] + fVals[4] * gVals[0];

    for(int j=0; j<4; j++) {
        finalValues[j] = ((uint64_t) fg[j]) & mask;
        carry = (uint64_t) (fg[j] >> 51);
        fg[j+1] += carry;
    }

    finalValues[4] = ((uint64_t) fg[4]) & mask;
    carry = (uint64_t) (fg[4] >> 51);
    finalValues[0] += 19ULL * carry;
    carry  = finalValues[0] >> 51;
    finalValues[0] &= mask;
    finalValues[1] += carry;
    carry  = finalValues[1] >> 51;
    finalValues[1] &= mask;
    finalValues[2] += carry;

    for(int k = 0; k < 5; k++) {
        h[k] = finalValues[k];
    }
}