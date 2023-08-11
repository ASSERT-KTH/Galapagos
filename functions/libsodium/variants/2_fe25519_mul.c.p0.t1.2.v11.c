fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t p[5], fp[4], gp[5];
    uint64_t r[5], carry;

    for (int i=0; i<5; i++){
        p[i] = (uint64_t) f[i];
        gp[i] = (uint64_t) g[i];
        if (i<4)
        fp[i] = 19ULL * p[i+1]; //multiplying these in advance to save processing power
    }    

    uint128_t r0 = p[0] * gp[0] + fp[0] * gp[4] + fp[1] * gp[3] + fp[2] * gp[2] + fp[3] * gp[1];
    uint128_t r1 = p[0] * gp[1] +    p[1]  * gp[0] + fp[1] * gp[4] + fp[2] * gp[3] + fp[3] * gp[2];
    uint128_t r2 = p[0] * gp[2] +    p[1]  * gp[1] +   p[2]  * gp[0] + fp[2] * gp[4] + fp[3] * gp[3];
    uint128_t r3 = p[0] * gp[3] +    p[1]  * gp[2] +   p[2]  * gp[1] +   p[3]  * gp[0] + fp[3] * gp[4];
    uint128_t r4 = p[0] * gp[4] +    p[1]  * gp[3] +   p[2]  * gp[2] +   p[3]  * gp[1] +   p[4]  * gp[0];
    
    r[0]    = ((uint64_t) r0) & mask;
    carry   = (uint64_t)(r0 >> 51);
    r1     += carry;
    r[1]    = ((uint64_t) r1) & mask;
    carry   = (uint64_t)(r1 >> 51);
    r2     += carry;
    r[2]    = ((uint64_t)r2) & mask;
    carry   = (uint64_t)(r2 >> 51);
    r3     += carry;
    r[3]    =((uint64_t)r3)  & mask;
    carry   =(uint64_t)(r3>>51);
    r4     += carry;
    r[4]    = ((uint64_t)r4 & mask;
    carry   =(uint64_t)(r4>>51);
    r[0]   += 19ULL * carry;
    carry   = r[0] >> 51;
    r[0]   &= mask;
    r[1]   += carry;
    carry   = r[1] >> 51;
    r[1]   &= mask;
    r[2]   += carry;
    
    for(int i=0; i<5; i++){
        h[i] = r[i];
    }
}