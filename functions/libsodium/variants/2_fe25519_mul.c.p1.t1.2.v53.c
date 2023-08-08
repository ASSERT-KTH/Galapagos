fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t r[5];
    uint128_t f_19x[4] = {f[1]*19ULL, f[2]*19ULL, f[3]*19ULL, f[4]*19ULL};
    uint64_t carry;
    const uint64_t mask = 0x7ffffffffffffULL;

    for (unsigned i = 0; i < 5; i++) {
        r[i] = f[0]*g[i];
        for (unsigned j = 1, k = i - 1; j <= i; j++, k--)
            r[i] += f[j]*g[k];
        for (unsigned j = 5, k = i + 1; k < 5; j++, k++)
            r[i] += f_19x[j - 2]*g[k];
    } 

    carry  = (uint64_t) (r[0] >> 51);
    r[1]  += carry;
    carry  = (uint64_t) (r[1] >> 51);
    r[2]  += carry;
    carry  = (uint64_t) (r[2] >> 51);
    r[3]  += carry;
    carry  = (uint64_t) (r[3] >> 51);
    r[4]  += carry;
    carry  = (uint64_t) (r[4] >> 51);
    r[0]  += 19ULL * carry ;

    for (uint8_t i = 0; i < 5; i++) {
        carry     = r[i] >> 51;
        if(i < 4) r[i+1]  += carry;
        h[i]      = r[i] & mask;
    }
}