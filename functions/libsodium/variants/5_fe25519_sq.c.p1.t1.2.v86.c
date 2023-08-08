void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t results[5];
    uint128_t values[5];
    uint128_t tempvals[7];
    uint64_t  intermediates[5];
    uint64_t  carry;

    for (int i = 0; i < 5; i++)
    {
        values[i] = (uint128_t) f[i];
    }

    tempvals[0] = values[0] << 1;
    tempvals[1] = values[1] << 1;

    for (int i = 1; i <= 3; i++) {
        tempvals[i+1] = 38ULL * values[i];
    }

    tempvals[5] = 19ULL * values[3];
    tempvals[6] = 19ULL * values[4];

    results[0] =   values[0] * values[0] + tempvals[2] * values[4] + tempvals[3] * values[3];
    results[1] = tempvals[0] * values[1] + tempvals[3] * values[4] + tempvals[5] * values[3];
    results[2] = tempvals[0] * values[2] + values[1] * values[1] + tempvals[4] * values[4];
    results[3] = tempvals[0] * values[3] + tempvals[1] * values[2] + tempvals[6] * values[4];
    results[4] = tempvals[0] * values[4] + tempvals[1] * values[3] + values[2] * values[2];

    for (int i = 0; i < 5; i++)
    {
        intermediates[i] = ((uint64_t) results[i]) & mask;
        if(i != 4) {
            carry  = (uint64_t) (results[i] >> 51);
            results[i+1] += carry;
        }
    }
    
    intermediates[0] += 19ULL * ((uint64_t)(results[4] >> 51));
    h[0] = intermediates[0] & mask;
    
    for (int i = 1; i < 5; i++) {
        carry  = intermediates[i-1] >> 51;
        intermediates[i] += carry;
        h[i] = intermediates[i] & mask;
    }

    carry  = h[1] >> 51;
    h[1] &= mask;
    h[2] += carry;
}
