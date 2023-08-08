fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t partF[5], partG[5];
    uint64_t r_val[5], carry;

    for(int i = 0; i < 5; i++) {
        partF[i] = (uint128_t)f[i];
        partG[i] = (uint128_t)g[i];
     }        

    for(int i = 1; i < 5; i++) {
        partF[i] = 19ULL * partF[i];
    }

    r[0] = partF[0] * partG[0] + partF[1] * partG[4] + partF[2] * partG[3] + partF[3] * partG[2] + partF[4] * partG[1];
    r[1] = partF[0] * partG[1] +    f[1] * partG[0] + partF[2] * partG[4] + partF[3] * partG[3] + partF[4] * partG[2];
    r[2] = partF[0] * partG[2] +    f[1] * partG[1] +    f[2] * partG[0] + partF[3] * partG[4] + partF[4] * partG[3];
    r[3] = partF[0] * partG[3] +    f[1] * partG[2] +    f[2] * partG[1] +    f[3] * partG[0] + partF[4] * partG[4];
    r[4] = partF[0] * partG[4] +    f[1] * partG[3] +    f[2] * partG[2] +    f[3] * partG[1] +    f[4] * partG[0];

    for(int i = 0; i < 5; i++) {
        r_val[i] = ((uint64_t) r[i]) & mask;
        carry = (uint64_t) (r[i] >> 51);

        if(i != 4) {
            r[i+1] += carry;
        }
        else {
            r[0] += 19ULL * carry;
            r_val[0] &= mask;
            carry = r[0] >> 51;
            r[0] &= mask;
            r[1] += carry;
        }
    }
    
    for(int i = 0; i < 5; i++) {
        h[i] = r_val[i];
    }
}