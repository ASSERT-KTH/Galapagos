fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t rad[5], fval[5], mult[5], gval[5];
    uint64_t  hval[5], extra;
    uint128_t constant19 = 19ULL;
    
    for(int i = 0; i < 5; i++) {
        fval[i] = (uint128_t) f[i];
        gval[i] = (uint128_t) g[i];
        if(i > 0) {
            mult[i] = constant19 * fval[i];
        }
    }

    rad[0] = fval[0] * gval[0] + mult[1] * gval[4] + mult[2] * gval[3] + mult[3] * gval[2] + mult[4] * gval[1];
    rad[1] = fval[0] * gval[1] + fval[1] * gval[0] + mult[2] * gval[4] + mult[3] * gval[3] + mult[4] * gval[2];
    rad[2] = fval[0] * gval[2] + fval[1] * gval[1] + fval[2] * gval[0] + mult[3] * gval[4] + mult[4] * gval[3];
    rad[3] = fval[0] * gval[3] + fval[1] * gval[2] + fval[2] * gval[1] + fval[3] * gval[0] + mult[4] * gval[4];
    rad[4] = fval[0] * gval[4] + fval[1] * gval[3] + fval[2] * gval[2] + fval[3] * gval[1] + fval[4] * gval[0];

    for(int i = 0; i < 5; i++) {
        hval[i] = ((uint64_t) rad[i]) & mask;
        extra  = (uint64_t) (rad[i] >> 51);
        if(i != 4) {
            rad[i+1] += extra;
        }
    }
    
    extra = hval[0] >>= 51;
    extra *= constant19;
    hval[0] += extra;
    hval[0] &= mask;
    
    extra = hval[1] >>= 51;
    hval[1] += extra;
    hval[1] &= mask;
    
    hval[2] += extra;
    
    for(int i = 0; i < 5; ++i)
    {
        h[i] = hval[i];
    }

}