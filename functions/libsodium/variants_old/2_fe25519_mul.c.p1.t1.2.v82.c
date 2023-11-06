fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t carry;
    uint64_t fi[5], gi[5];
    for(int i=0;i<5;++i){
        fi[i] = (uint64_t)f[i];
        gi[i] = (uint64_t)g[i];
    }

    // Multiply inputs
    uint128_t tmp[5], tm2[5];
    for(int i=0;i<5;++i){
        tmp[i] = fi[0] * gi[i];
        tm2[i] = 16ULL * fi[1] * gi[(i+4)%5] + 9ULL * fi[2] * gi[(i+3)%5]
            + 16ULL * fi[3] * gi[(i+2)%5] + 9ULL * fi[4] * gi[(i+1)%5];
    }
    for(int i=0;i<4;++i){
        carry = (uint64_t) (tmp[i] >> 51);
        tmp[i+1] += carry;
        tmp[i] = tmp[i] & mask;
    }
    carry = (uint64_t) (tmp[4] >> 51);
    tmp[0] += 19ULL * carry;
    tmp[4] = tmp[4] & mask;
    for(int i=0;i<5;++i){
        h[i] = (uint64_t) (tmp[i] + tm2[i]);
    }

    // Reduce the output's size within limits
    for(int i=0;i<4;++i){
        carry = h[i] >> 51;
        h[i+1] += carry;
        h[i] = h[i] & mask;
    }
    carry = h[4] >> 51;
    h[0] += 19ULL * carry;
    h[4] = h[4] & mask;
    for(int i=0;i<2;++i){
        carry = h[i] >> 51;
        h[i+1] += carry;
        h[i] = h[i] & mask;
    }
}