fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t a[5], b[5], ab[5], abx19[4];
    uint64_t  r[5], carry, aux;

    for (int i = 0; i < 5; i++) {
        a[i] = (uint128_t) f[i];
        b[i] = (uint128_t) g[i];
    }

    for (int x = 1; x <= 4; x++)
        abx19[x-1]  = a[x] * 19ULL;

    ab[0] = a[0] * b[0] + abx19[0] * b[4] + abx19[1] * b[3] + abx19[2] * b[2] + abx19[3] * b[1];
    ab[1] = a[0] * b[1] +    a[1] * b[0] + abx19[1] * b[4] + abx19[2] * b[3] + abx19[3] * b[2];
    ab[2] = a[0] * b[2] +    a[1] * b[1] +     a[2] * b[0] + abx19[2] * b[4] + abx19[3] * b[3];
    ab[3] = a[0] * b[3] +    a[1] * b[2] +     a[2] * b[1] +     a[3] * b[0] + abx19[3] * b[4];
    ab[4] = a[0] * b[4] +    a[1] * b[3] +     a[2] * b[2] +     a[3] * b[1] +     a[4] * b[0];

    for (int y = 0; y < 5; y++) {
        r[y] = ab[y] & mask;
        carry = ab[y] >> 51;
        ab[(y+1) % 5] += carry;
    }

    aux = r[0] + 19ULL * (ab[0] >> 51);
    r[0] = aux & mask, r[1] += aux >> 51;

    aux = r[1] + (ab[1] >> 51);
    r[1] = aux & mask, r[2] += aux >> 51;

    memcpy(h, r, 5 * sizeof(uint64_t));
}