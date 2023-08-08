fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], frc[5];
    uint64_t rOut[5];
    uint64_t carry;

    for(int i = 0; i < 5; ++i){
        frc[i] = (uint128_t) f[i];
    }

    uint128_t f0_2 = frc[0] << 1;
    uint128_t f1_2 = frc[1] << 1;

    uint128_t f1_38 = 38ULL * frc[1];
    uint128_t f2_38 = 38ULL * frc[2];
    uint128_t f3_38 = 38ULL * frc[3];

    uint128_t f3_19 = 19ULL * frc[3];
    uint128_t f4_19 = 19ULL * frc[4];

    r[0] =   frc[0] * frc[0] + f1_38 * frc[4] + f2_38 * frc[3];
    r[1] = f0_2 * frc[1] + f2_38 * frc[4] + f3_19 * frc[3];
    r[2] = f0_2 * frc[2] +    frc[1] * frc[1] + f3_38 * frc[4];
    r[3] = f0_2 * frc[3] +  f1_2 * frc[2] + f4_19 * frc[4];
    r[4] = f0_2 * frc[4] +  f1_2 * frc[3] +    frc[2] * frc[2];

    for(int i=0; i<5; ++i) {
        rOut[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1 % 5]  += carry;
        rOut[i]     = ((uint64_t) r[i]) & mask;
        carry       = (uint64_t) (r[i] >> 51);
     }

    rOut[0] += 19ULL * carry;
    carry   = rOut[0] >> 51;
    rOut[0] &= mask;
    rOut[1] += carry;
    carry   = rOut[1] >> 51;
    rOut[1] &= mask;
    rOut[2] += carry;

    for(int i=0; i<5; ++i)
        h[i] = rOut[i];
}
