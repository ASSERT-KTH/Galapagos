fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t  r00, r01, r02, r03, r04;
    uint64_t  carry;

    uint128_t fvalues[5];
    uint128_t gvalues[5];
    uint128_t multi_values[5];
    uint128_t results[5];
    
    for (int i = 0; i < 5; i++) {
        fvalues[i] = (uint128_t) f[i];
        gvalues[i] = (uint128_t) g[i];

        if (i != 0) {
            multi_values[i] = 19ULL * fvalues[i];
        }
    }

    results[0] = fvalues[0] * gvalues[0] + multi_values[1] * gvalues[4] + multi_values[2] * gvalues[3] + multi_values[3] * gvalues[2] + multi_values[4] * gvalues[1];
    results[1] = fvalues[0] * gvalues[1] +    fvalues[1] * gvalues[0] + multi_values[2] * gvalues[4] + multi_values[3] * gvalues[3] + multi_values[4] * gvalues[2];
    results[2] = fvalues[0] * gvalues[2] +    fvalues[1] * gvalues[1] +    fvalues[2] * gvalues[0] + multi_values[3] * gvalues[4] + multi_values[4] * gvalues[3];
    results[3] = fvalues[0] * gvalues[3] +    fvalues[1] * gvalues[2] +    fvalues[2] * gvalues[1] +    fvalues[3] * gvalues[0] + multi_values[4] * gvalues[4];
    results[4] = fvalues[0] * gvalues[4] +    fvalues[1] * gvalues[3] +    fvalues[2] * gvalues[2] +    fvalues[3] * gvalues[1] +    fvalues[4] * gvalues[0];

    for (int i = 0; i < 4; i++) {
        r00    = ((uint64_t) results[i]) & mask;
        carry  = (uint64_t) (results[i] >> 51);
        results[i+1] += carry;
        h[i]   = ((uint64_t) results[i+1]) & mask;
    }

    carry  = (uint64_t) (results[4] >> 51);
    r00   += 19ULL * carry;
    carry  = r00 >> 51;
    r00   &= mask;
    h[1]  += carry;
    carry  = h[1] >> 51;
    h[1]  &= mask;
    h[2]  += carry;

    h[0] = r00;
    h[4] = (((uint64_t) results[4]) + carry) & mask;
}