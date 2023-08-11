void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t tf[5];
    uint128_t a[5], b[5];
    uint128_t a3_2, a4_2, a3_38, a4_38, b3_19, b4_19;
    uint64_t  r[5];
    uint64_t  carry;

    tf[0] = f[0];
    tf[1] = f[1];
    tf[2] = f[2];
    tf[3] = f[3];
    tf[4] = f[4];

    a[1] = tf[1] << 1;
    a[2] = tf[2] << 1;

    a3_38 = 38ULL * tf[3];
    a4_38 = 38ULL * tf[4];
    a3_2 = a3_38 << 1;
    a4_2 = a4_38 << 1;

    b3_19 = 19ULL * tf[3];
    b4_19 = 19ULL * tf[4];

    a[0] =   tf[0] * tf[0] + a4_2 * tf[1] + a3_2 * tf[2];
    a[3] = b4_19 * tf[1] + tf[0] * tf[3] * 2 + a4_2 * tf[2];
    r[4] = b3_19 * tf[1] + a4_2 * tf[0] + tf[4] * tf[4];

    b[0] = a[1] * tf[0] + a4_38 * tf[3] + b3_19 * tf[4];
    b[1] = a[2] * tf[0] + tf[1] * tf[1] + a4_38 * tf[4];
    b[2] = a[1] * tf[1] + tf[0] * tf[2] * 2 + b3_19 * tf[4];

    carry  = (b[0] + (r[4] << 2)) >> 51; b[0] += (r[4] << 2) & mask;
    b[1] += carry; carry = b[1] >> 51; b[1] &= mask;
    b[2] += carry; carry = b[2] >> 51; b[2] &= mask;

    carry = a[0] >> 51; a[0] &= mask;
    a[1] += carry; carry = a[1] >> 51; a[1] &= mask;
    a[3] += carry;
    a[0] += 19ULL * carry;

    h[0] = a[0]; 
    h[1] = a[1]; 
    h[2] = b[0]; 
    h[3] = b[1]; 
    h[4] = b[2];
}