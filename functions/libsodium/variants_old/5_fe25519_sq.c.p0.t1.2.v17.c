fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_values[5], multiplyF[5], sumMultiplicity[5], r[5], shiftedR[5];
    uint64_t carry;

    for(uint64_t i=0; i<5; ++i)
    {
        mult_values[i] = 38ULL;
        sum_values[i] = 19ULL;
        f_values[i] = (uint128_t)f[i];
        multiplyF[i]= f_values[i] << 1;
    }

    multiplyF[0] *= 1;
    multiplyF[2]  = f_values[2]  * mult_values[2];
    multiplyF[3]  = f_values[3]  * mult_values[3];
    sumMultiplicity[3] = sum_values[3]  * f_values[3];
    sumMultiplicity[4] = sum_values[4]  * f_values[4];

    r[0] =  f_values[0] * f_values[0]  +         multiplyF[3]     +  multiplyF[4];
    r[1] =   multiplyF[0] * f_values[1]  + multiplyF[4] + sumMultiplicity[3];
    r[2] =   multiplyF[0] * m_values[2] + f_values[1]* m_values[1] + multiplyF[4];
    r[3] =   multiplyF[0] * f_values[3] +  multiplyF[1] * f_values[2] + sumMultiplicity[4];
    r[4] =   multiplyF[0] * f_values[4] +  multiplyF[1] * f_values[3]   +  f_values[2] * f_values[2];

    for (uint64_t i = 0; i<5; ++i)
    {
        carry = (uint64_t)(r[i] >> 51);
        shiftedR[i] = ((uint64_t) r[i]) & mask;
        r[i+1] += carry;
        if(i == 4)
        {
            shiftedR[0] += 19ULL * carry;
        }
    }

    for (uint64_t i = 0; i<3; ++i)
    {
        carry = shiftedR[i] >> 51;
        shiftedR[i] &= mask;
        shiftedR[i+1] += carry;
    }

    h[0] = shiftedR[0];
    h[1] = shiftedR[1];
    h[2] = shiftedR[2];
    h[3] = shiftedR[3];
    h[4] = shiftedR[4];
}