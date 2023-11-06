Variant 1:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint128_t r[5] = {
         f[0] * g[0] + 19ULL * f[1] * g[4] + 19ULL * f[2] * g[3] + 19ULL * f[3] * g[2] + 19ULL * f[4] * g[1],
         f[0] * g[1] + f[1] * g[0] + 19ULL * f[2] * g[4] + 19ULL * f[3] * g[3] + 19ULL * f[4] * g[2],
         f[0] * g[2] + f[1] * g[1] + f[2] * g[0] + 19ULL * f[3] * g[4] + 19ULL * f[4] * g[3],
         f[0] * g[3] + f[1] * g[2] + f[2] * g[1] + f[3] * g[0] + 19ULL * f[4] * g[4],
         f[0] * g[4] + f[1] * g[3] + f[2] * g[2] + f[3] * g[1] + f[4] * g[0]
    };

    uint64_t carry;
    for (int i = 0; i < 5; ++i) {
        h[i] = ((uint64_t) r[i]) & 0x7ffffffffffffULL;
        carry = (uint64_t) (r[i] >> 51);
        h[(i+1)%5] += carry;
        carry = h[(i+1)%5] >> 51;
        h[(i+1)%5] &= 0x7ffffffffffffULL;
        h[(i+2)%5] += carry;
    }
}


Variant 2:

void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    uint128_t sum[5] = {0};
    uint64_t carry;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            sum[i+j] += f[i]*g[j];
            if (i != j) {
                sum[i+j] += f[j]*g[i];
            }
        }
    }

    sum[0] += 19ULL * sum[4];
    for (int i = 4; i > 0; i--) {
        sum[i] = 19ULL * sum[i-1];
    }

    for (int i = 0; i < 5; i++) {
        h[i] = ((uint64_t) sum[i]) & 0x7ffffffffffffULL;
        carry = (uint64_t) (sum[i] >> 51);
        h[(i+1)%5] += carry;
        carry = h[(i+1)%5] >> 51;
        h[(i+1)%5] &= 0x7ffffffffffffULL;
        h[(i+2)%5] += carry;
    }
}
