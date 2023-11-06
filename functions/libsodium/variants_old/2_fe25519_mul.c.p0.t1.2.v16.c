fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r0, r1, r2, r3, r4;
    uint128_t f_[5];
    uint128_t g_[5];
    uint128_t f_19[5];
    uint64_t r_[5];
    uint64_t carry;
    int i;

    for(i = 0; i < 5; i++) {
        f_[i] = (uint128_t) f[i];
        g_[i] = (uint128_t) g[i];
    }

    for(i = 1; i < 5; i++) {
        f_19[i] = 19ULL * f_[i];
    }

    r0 = f_[0] * g_[0] + f_19[4] * g_[1] + f_19[3] * g_[2] + f_19[2] * g_[3] + f_19[1] * g_[4];
    r1 = f_[0] * g_[1] +    f_[1] * g_[0] + f_19[4] * g_[2] + f_19[3] * g_[3] + f_19[2] * g_[4];
    r2 = f_[0] * g_[2] +    f_[1] * g_[1] +    f_[2] * g_[0] + f_19[4] * g_[3] + f_19[3] * g_[4];
    r3 = f_[0] * g_[3] +    f_[1] * g_[2] +    f_[2] * g_[1] +    f_[3] * g_[0] + f_19[2] * g_[4];
    r4 = f_[0] * g_[4] +    f_[1] * g_[3] +    f_[2] * g_[2] +    f_[3] * g_[1] +    f_[4] * g_[0];

    r_[0] = ((uint64_t) r0) & mask;
    carry = (uint64_t) (r0 >> 51);
    r1   += carry;
    r_[1] = ((uint64_t) r1) & mask;
    carry = (uint64_t) (r1 >> 51);
    r2   += carry;
    r_[2] = ((uint64_t) r2) & mask;
    carry = (uint64_t) (r2 >> 51);
    r3   += carry;
    r_[3] = ((uint64_t) r3) & mask;
    carry = (uint64_t) (r3 >> 51);
    r4   += carry;
    r_[4] = ((uint64_t) r4) & mask;
    carry = (uint64_t) (r4 >> 51);
    r_[0]+= 19ULL * carry;
    carry = r_[0] >> 51;
    r_[0]&= mask;
    r_[1]+= carry;
    carry = r_[1] >> 51;
    r_[1]&= mask;
    r_[2]+= carry;

    for(i = 0; i < 5; i++) {
        h[i] = r_[i];
    }
}
