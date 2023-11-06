fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_values[5], doubles[3], mults[6];
    uint64_t  r_values[5];
    uint64_t  carry;


    for(int i=0; i<5; ++i)
        f_values[i] = (uint128_t) f[i];

    doubles[0] = f_values[0] << 1;
    doubles[1] = f_values[1] << 1;
    doubles[2] = f_values[4] << 1;

    mults[0] = 38ULL * f_values[1];
    mults[1] = 38ULL * f_values[2];
    mults[2] = 38ULL * f_values[3];
    mults[3] = 19ULL * f_values[3];
    mults[4] = 19ULL * f_values[4];
    mults[5] = 19ULL * carry;


    r0 =   f_values[0] * f_values[0] + mults[0] * f_values[4] + mults[1] * f_values[3];
    r1 = doubles[0] * f_values[1] + mults[1] * f_values[4] + mults[3] * f_values[3];
    r2 = doubles[0] * f_values[2] +    f_values[1] * f_values[1] + mults[2] * f_values[4];
    r3 = doubles[0] * f_values[3] +  doubles[1] * f_values[2] + mults[4] * f_values[4];
    r4 = doubles[0] * f_values[4] +  doubles[1] * f_values[3] +    f_values[2] * f_values[2];

    for (int i = 0; i < 5; ++i) {
        r_values[i] = ((uint64_t) (i == 0 ? r0 : (i == 1 ? r1 : (i == 2 ? r2 : (i == 3 ? r3 : r4))))) & mask;
        carry  = (uint64_t) ((i == 0 ? r0 : (i == 1 ? r1 : (i == 2 ? r2 : (i == 3 ? r3 : r4))) >> 51);
        if(i<4){
            if(i == 0) r1 += carry;
            else if(i == 1) r2 += carry;
            else if(i == 2) r3 += carry;
            else if(i == 3) r4 += carry;
        }
     }

    r_values[0] += mults[5] * carry;
    carry  = r_values[0] >> 51;
    r_values[0] &= mask;
    r_values[1] += carry;
    carry  = r_values[1] >> 51;
    r_values[1] &= mask;
    r_values[2] += carry;

    for(int i=0; i<5; ++i)
        h[i] = r_values[i];
}