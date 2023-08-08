fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t f_values[5];
    uint128_t f2_values[5];
    uint64_t  r_values[5];
    uint64_t  carry;

    for(int i = 0; i<5; i++) {
        f_values[i] = (uint128_t) f[i];
    } 

    f_values[2] = (f_values[0]<<1);
    f_values[7] = (f_values[1]<<1);

    f_values[3] = (38ULL * f_values[1]);
    f_values[4] = (38ULL * f_values[2]);
    f_values[5] = (38ULL * f_values[3]);

    f_values[6] = (19ULL * f_values[2]);
    f_values[8] = (19ULL * f_values[4]);

    r_values[0] =   f_values[0] * f_values[0] + f_values[3] * f_values[4] + f_values[4] * f_values[5];
    r_values[1] = f_values[2] * f_values[1] + f_values[3] * f_values[4] + f_values[6] * f_values[2];
    r_values[2] = f_values[2] * f_values[2] +    f_values[1] * f_values[1] + f_values[5] * f_values[8];
    r_values[3] = f_values[2] * f_values[3] +  f_values[7] * f_values[4] + f_values[8] * f_values[8];
    r_values[4] = f_values[2] * f_values[4] +  f_values[7] * f_values[3] + f_values[2] * f_values[2];

    for(int i = 0; i<5;i++){
        f2_values[i] = ((uint64_t) r_values[i]) & mask;
        carry = (uint64_t) (r_values[i] >> 51);
        if((i + 1) != 5) r_values[i+1] +=  carry;
        if (i == 4) f2_values[0] += (19ULL * carry);
    }
    carry = (f2_values[0] >> 51);
    for(int i = 1; i<5;i++){
        f2_values[(i - 1)]  = f2_values[i - 1] & mask;
        f2_values[i] += carry;
        carry = f2_values[i] >> 51;
    }

    for(int i =0; i<5;i++){ h[i] =  f2_values[i];}
}