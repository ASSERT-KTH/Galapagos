fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fCopy[5], gCopy[5];
    uint128_t fTimes19[4];
    uint64_t  rFinal[5], carry;

    for (int i=0; i<5; i++) {  
        fCopy[i] = (uint128_t) f[i];
        gCopy[i] = (uint128_t) g[i];
        if (i != 4) 
            fTimes19[i] = 19ULL * f[i];
    }

    r[0] = fCopy[0] * gCopy[0] + fTimes19[1] * gCopy[4] + fTimes19[2] * gCopy[3] + fTimes19[3] * gCopy[2] + fTimes19[0] * gCopy[1];
    r[1] = fCopy[0] * gCopy[1] + fCopy[1] * gCopy[0] + fTimes19[2] * gCopy[4] + fTimes19[3] * gCopy[3] + fTimes19[0] * gCopy[2];
    r[2] = fCopy[0] * gCopy[2] + fCopy[1] * gCopy[1] + fCopy[2] * gCopy[0] + fTimes19[3] * gCopy[4] + fTimes19[0] * gCopy[3];
    r[3] = fCopy[0] * gCopy[3] + fCopy[1] * gCopy[2] + fCopy[2] * gCopy[1] + fCopy[3] * gCopy[0] + fTimes19[0] * gCopy[4];
    r[4] = fCopy[0] * gCopy[4] + fCopy[1] * gCopy[3] + fCopy[2] * gCopy[2] + fCopy[3] * gCopy[1] + fCopy[4] * gCopy[0];

    for (int i = 0; i < 5; i++) {
        rFinal[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[(i + 1) % 5] += carry;
    }

    rFinal[0] += 19ULL * ((uint64_t) (r[4] >> 51));
    carry  = rFinal[0] >> 51;
    rFinal[0] &= mask;

    rFinal[1] += carry;
    carry  = rFinal[1] >> 51;
    rFinal[1] &= mask;

    rFinal[2] += carry;
    
    for (int i=0; i<5; i++) 
        h[i] = rFinal[i];
}
