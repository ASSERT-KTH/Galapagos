fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], a[5], b[5];
    uint128_t f_19[4];
    uint64_t  r_res[5], carry;

    for(int i = 0; i < 5; i++){
        a[i] = (uint128_t) f[i];
        b[i] = (uint128_t) g[i];
    }

    for (int i = 1; i < 5; i++) {
        f_19[i-1] = 19ULL * a[i];
    }

    r[0] = a[0] * b[0] + f_19[3] * b[4] + f_19[2] * b[3] + f_19[1] * b[2] + f_19[0] * b[1];
    r[1] = a[0] * b[1] +    a[1] * b[0] + f_19[3] * b[4] + f_19[2] * b[3] + f_19[1] * b[2];
    r[2] = a[0] * b[2] +    a[1] * b[1] +    a[2] * b[0] + f_19[3] * b[4] + f_19[2] * b[3];
    r[3] = a[0] * b[3] +    a[1] * b[2] +    a[2] * b[1] +    a[3] * b[0] + f_19[3] * b[4];
    r[4] = a[0] * b[4] +    a[1] * b[3] +    a[2] * b[2] +    a[3] * b[1] +    a[4] * b[0];

    for(int i=0;i<5;i++){
        r_res[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if(i<4) r[i+1]+= carry;
    }
    r_res[0] += 19ULL * carry;   
    for(int i=0;i<4;i++){
        carry  = r_res[i] >> 51;
        r_res[i] &= mask;
        r_res[i+1] += carry;
    }

    for(int i = 0; i < 5; i++){
        h[i] = r_res[i];
    }

}