fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t f_val[5];
    uint128_t f_vals_mult_19[4];
    uint128_t g_val[5];
    uint64_t carry, r_val[5];

    for(int i = 0; i < 5; i++) {
        f_val[i] = (uint128_t) f[i];
        g_val[i] = (uint128_t) g[i];
        if(i < 4){
            f_vals_mult_19[i] = 19ULL * f_val[i];
        }
    }

    r[0] = f_val[0]*g_val[0] + f_vals_mult_19[0] * g_val[4] + f_vals_mult_19[1] * g_val[3] + f_vals_mult_19[2] * g_val[2] + f_vals_mult_19[3] * g_val[1];
    r[1] = f_val[0]*g_val[1] + f_val[1]*g_val[0] + f_vals_mult_19[1] * g_val[4] + f_vals_mult_19[2] * g_val[3] + f_vals_mult_19[3] * g_val[2];
    r[2] = f_val[0]*g_val[2] + f_val[1]*g_val[1] + f_val[2]*g_val[0] + f_vals_mult_19[2] * g_val[4] + f_vals_mult_19[3] * g_val[3];
    r[3] = f_val[0]*g_val[3] + f_val[1]*g_val[2] + f_val[2]*g_val[1] + f_val[3]*g_val[0] + f_vals_mult_19[3] * g_val[4];
    r[4] = f_val[0]*g_val[4] + f_val[1]*g_val[3] + f_val[2]*g_val[2] + f_val[3]*g_val[1] + f_val[4]*g_val[0];

    for(int i = 0; i < 5; i++){
        r_val[i] = ((uint64_t)r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);
        if(i < 4){
            r[i+1] += carry;
        }
        else {
            r_val[0] += 19ULL * carry;
            carry = r_val[0] >> 51;
            r_val[0] &= mask;
            r_val[1] += carry;
            carry = r_val[1] >> 51;
            r_val[1] &= mask;
            r_val[2] += carry;
        }
    }

    for(int i = 0; i < 5; i++){
        h[i] = r_val[i];
    }
}