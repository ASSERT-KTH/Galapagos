fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t r[5]={0}, carry=0;
    uint128_t f_vals[5]={0}, f_shiftedVals[5]={0};

    for (int i = 0; i<5; i++)
    {
        f_vals[i] = (uint128_t) f[i];
    }

    for (int i = 0; i<2; i++)
    {
    	f_shiftedVals[i] = f_vals[i] << 1;
    }

    f_shiftedVals[2] =  38ULL * f_vals[1];
    f_shiftedVals[3] = 38ULL  * f_vals[2];
    f_shiftedVals[4] = 38ULL  * f_vals[3];

    r[0] =   f_vals[0] * f_vals[0] + 38ULL * f_vals[1] * f_vals[4] + 38ULL * f_vals[2] * f_vals[3];
    r[1] = 2 * f_vals[0] * f_vals[1] + 38ULL * f_vals[2] * f_vals[4] + 19ULL * f_vals[3] * f_vals[3];
    r[2] = 2 * f_vals[0] * f_vals[2] +    f_vals[1] * f_vals[1] + 38ULL * f_vals[3] * f_vals[4];
    r[3] = 2 * f_vals[0] * f_vals[3] + 2 * f_vals[1] * f_vals[2] + 19ULL * f_vals[4] * f_vals[4];
    r[4] = 2 * f_vals[0] * f_vals[4] + 2 * f_vals[1] * f_vals[3] +    f_vals[2] * f_vals[2];

    for (int i = 0; i<4; i++){
        h[i] = (r[i] & mask);
        carry = (uint64_t)(r[i] >> 51);		
        r[i+1] += carry;
    }

    h[4] = r[4] & mask;
    carry = (uint64_t) (r[4] >> 51);
    h[0] += 19ULL * carry;
    carry = h[0] >> 51;
    h[0] &= mask;
    h[1] += carry;

    carry = h[1] >> 51;
    h[1] &=  mask;
    h[2] += carry;
}