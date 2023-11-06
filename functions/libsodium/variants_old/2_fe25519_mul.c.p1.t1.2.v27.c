fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5];
    uint128_t fi[5], gi[5], f19[4];
    uint64_t carry, ri[5];

    for(int i=0; i<5; i++){
        fi[i] = (uint128_t) f[i];
        gi[i] = (uint128_t) g[i];
    }

    for(int i=1; i<5; i++)
        f19[i-1] = 19ULL * fi[i];

    r[0] = fi[0] * gi[0] + f19[0] * gi[4] + f19[1] *gi[3] + f19[2] *gi[2] + f19[3] *gi[1];
    r[1] = fi[0] * gi[1] + fi[1] * gi[0] + f19[1] *gi[4] + f19[2] *gi[3] + f19[3] *gi[2];
    r[2] = fi[0] * gi[2] + fi[1] * gi[1] + fi[2] * gi[0] + f19[2] *gi[4] + f19[3] *gi[3];
    r[3] = fi[0] * gi[3] + fi[1] * gi[2] + fi[2] * gi[1] + fi[3] * gi[0] + f19[3] *gi[4];
    r[4] = fi[0] * gi[4] + fi[1] * gi[3] + fi[2] * gi[2] + fi[3] * gi[1] +    fi[4] * gi[0];

    for(int i=0; i<5; i++){
        ri[i]    = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
    }

    ri[0]  += 19ULL * carry;
    carry  = ri[0] >> 51;
    ri[0]  &= mask;
    ri[1]  += carry;
    carry   = ri[1] >> 51;
    ri[1]  &= mask;
    ri[2]  += carry;

    for(int i=0; i<5; i++)
        h[i] = ri[i];
}