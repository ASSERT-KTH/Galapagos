fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t newMask = 0x7ffffffffffffULL;
    uint128_t rAllZeros[5], fAllZeros[5];
    uint128_t multipliers[4];
    uint128_t nodes[5];
    uint64_t residues[5];
    uint64_t carry;

    for (int i = 0; i < 5; i++) {
     fAllZeros[i] = (uint128_t) f[i];
     nodes[i] = (uint128_t) g[i];
    }

    for (int p = 1; p < 5; p++) {
     multipliers[p - 1] = 19ULL * fAllZeros[p];
    }

    rAllZeros[0] = fAllZeros[0] * nodes[0] + multipliers[0] * nodes[4] + multipliers[1] * nodes[3] + multipliers[2] * nodes[2] + multipliers[3] * nodes[1];
    rAllZeros[1] = fAllZeros[0] * nodes[1] +    fAllZeros[1] * nodes[0] + multipliers[1] * nodes[4] + multipliers[2] * nodes[3] + multipliers[3] * nodes[2];
    rAllZeros[2] = fAllZeros[0] * nodes[2] +    fAllZeros[1] * nodes[1] +    fAllZeros[2] * nodes[0] + multipliers[2] * nodes[4] + multipliers[3] * nodes[3];
    rAllZeros[3] = fAllZeros[0] * nodes[3] +    fAllZeros[1] * nodes[2] +    fAllZeros[2] * nodes[1] +    fAllZeros[3] * nodes[0] + multipliers[3] * nodes[4];
    rAllZeros[4] = fAllZeros[0] * nodes[4] +    fAllZeros[1] * nodes[3] +    fAllZeros[2] * nodes[2] +    fAllZeros[3] * nodes[1] +    fAllZeros[4] * nodes[0];

    for (int i = 0; i < 5; i++) {
        residues[i] = ((uint64_t) rAllZeros[i]) & newMask;
        carry = (uint64_t) (rAllZeros[i] >> 51);
        if (i < 4) {
            rAllZeros[i + 1] += carry;
        }
    }

    residues[0] += 19ULL * carry;
    for (int i = 0; i < 4; i++) {
        carry = residues[i] >> 51;
        residues[i] &= newMask;
        residues[i + 1] += carry;
    }

    for (int i = 0; i < 5; i++) {
        h[i] = residues[i];
    }
}