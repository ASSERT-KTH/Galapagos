fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t fParts[5];
    uint128_t f19Parts[5];
    uint128_t gParts[5];
    uint64_t  rParts[5];
    uint64_t  carry;

    for (int i=0; i<5; i++) {
        fParts[i] = (uint128_t)f[i];
        gParts[i] = (uint128_t)g[i];
        if (i != 0) {
            f19Parts[i] = 19ULL * fParts[i];
        }
    }

    r0 = fParts[0] * gParts[0] + f19Parts[1] * gParts[4] + f19Parts[2] * gParts[3] + f19Parts[3] * gParts[2] + f19Parts[4] * gParts[1];
    r1 = fParts[0] * gParts[1] + fParts[1] * gParts[0] + f19Parts[2] * gParts[4] + f19Parts[3] * gParts[3] + f19Parts[4] * gParts[2];
    r2 = fParts[0] * gParts[2] + fParts[1] * gParts[1] + fParts[2] * gParts[0] + f19Parts[3] * gParts[4] + f19Parts[4] * gParts[3];
    r3 = fParts[0] * gParts[3] + fParts[1] * gParts[2] + fParts[2] * gParts[1] + fParts[3] * gParts[0] + f19Parts[4] * gParts[4];
    r4 = fParts[0] * gParts[4] + fParts[1] * gParts[3] + fParts[2] * gParts[2] + fParts[3] * gParts[1] + fParts[4] * gParts[0];

    uint128_t rPartsTemp[5] = {r0, r1, r2, r3, r4};

    for (int i=0; i<4; i++) {
        rParts[i] = ((uint64_t)rPartsTemp[i]) & mask;
        carry = (uint64_t)(rPartsTemp[i] >> 51);
        rPartsTemp[i+1] += carry;
    }
    rParts[4] = ((uint64_t)rPartsTemp[4]) & mask;
    carry  = (uint64_t) (rPartsTemp[4] >> 51);
    rParts[0] += 19ULL * carry;
    carry  = rParts[0] >> 51;
    rParts[0] &= mask;
    rParts[1] += carry;
    carry  = rParts[1] >> 51;
    rParts[1] &= mask;
    rParts[2] += carry;

    for (int i=0; i<5; i++) {
        h[i] = rParts[i];
    }
}