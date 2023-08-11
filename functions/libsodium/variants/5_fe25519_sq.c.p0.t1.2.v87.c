fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fq[5];
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  carry;

    for (int i = 0; i < 5; i++) {
        fq[i] = (uint128_t)f[i];
    }

    f0_2 = fq[0] << 1;
    f1_2 = fq[1] << 1;

    f1_38 = 38ULL * fq[1];
    f2_38 = 38ULL * fq[2];
    f3_38 = 38ULL * fq[3];

    f3_19 = 19ULL * fq[3];
    f4_19 = 19ULL * fq[4];

    r[0] =   fq[0] * fq[0] + f1_38 * fq[4] + f2_38 * fq[3];
    r[1] = f0_2 * fq[1] + f2_38 * fq[4] + f3_19 * fq[3];
    r[2] = f0_2 * fq[2] +    fq[1] * fq[1] + f3_38 * fq[4];
    r[3] = f0_2 * fq[3] +  f1_2 * fq[2] + f4_19 * fq[4];
    r[4] = f0_2 * fq[4] +  f1_2 * fq[3] +    fq[2] * fq[2];

    
    for (int j = 0; j < 5; j++) {
        h[j]   = ((uint64_t) r[j]) & mask;
        carry  = (uint64_t) (r[j] >> 51);
        r[(j+1)%5]+= carry; 
        h[j]   =  h[j] & mask;
        carry  = h[j] >> 51; 
        h[j]   =  h[j]& mask;
        h[(j+2)%5]+= carry;
    }
}