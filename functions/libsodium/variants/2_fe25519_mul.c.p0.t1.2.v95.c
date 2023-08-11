fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t fVal[5], gVal[5];
    uint128_t f_vals[4];

    for (int i = 0; i < 5; ++i) {
        fVal[i] = (uint128_t) f[i];
        gVal[i] = (uint128_t) g[i]; 
    }
    
    for (int i = 1; i < 5; ++i) {
        f_vals[i - 1] = 19ULL * fVal[i];
    }

    r[0] = fVal[0] * gVal[0] + f_vals[0] * gVal[4] + f_vals[1] * gVal[3] + f_vals[2] * gVal[2] + f_vals[3] * gVal[1];
    r[1] = fVal[0] * gVal[1] +       fVal[1]  * gVal[0] + f_vals[1] * gVal[4] + f_vals[2] * gVal[3] + f_vals[3] * gVal[2];
    r[2] = fVal[0] * gVal[2] +       fVal[1]  * gVal[1] +    fVal[2] * gVal[0] + f_vals[2] * gVal[4] + f_vals[3] * gVal[3];
    r[3] = fVal[0] * gVal[3] +       fVal[1]  * gVal[2] +    fVal[2] * gVal[1] +    fVal[3] * gVal[0] + f_vals[3] * gVal[4];
    r[4] = fVal[0] * gVal[4] +       fVal[1]  * gVal[3] +    fVal[2] * gVal[2] +    fVal[3] * gVal[1] +    fVal[4] * gVal[0];

    uint64_t  r_vals[5], carry;

    for (int i = 0; i < 5; ++i) {
        r_vals[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if (i != 4) {
            r[i+1] += carry;
        }
        else{
            r_vals[0] += 19ULL * carry;
        }
    }

    carry  = r_vals[0] >> 51;
    r_vals[0] &= mask;
    
    r_vals[1] += carry;
    carry = r_vals[1] >> 51;
    r_vals[1] &= mask;
    
    r_vals[2]   += carry;
    
    for (int i = 0; i < 5; ++i) {
        h[i] = r_vals[i];
    }
}