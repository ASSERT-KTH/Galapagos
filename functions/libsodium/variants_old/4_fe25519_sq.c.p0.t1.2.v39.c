void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t t0 = f[0];
    int32_t t1 = f[1];
    int64_t t0_t0 = 1LL*t0*t0;
    h[0] = t0_t0;
    h[1] = 2LL*t0*t1;
    
    for (int i = 2; i < 10; i++) {
        h[i] = 0;
    }

    int64_t carry = 0;

    for (int i = 0; i < 10; i++) {
        carry += h[i];
        h[i] = carry & ((1 << 26) - 1);
        carry >>= 26;
        if ((i & 1) && (i / 2 < 9)) {
            int32_t next_term = f[i/2 + 1];
            h[i/2 + 1] += 2LL*t0*next_term;
            for (int j = i/2+2; j < 10; j++) {
                h[j] += (i & 2 ? 38LL: 19LL)*next_term*f[j - i/2 - 1];
            }
        }
    }

    h[9] -= 1 << 24;
    carry = (h[9] >> 25);
    h[9] &= (1 << 24) - 1;
    carry *= 19;
    h[0] += carry;
    
    for (int i = 0; i < 10; i++) {
        carry += h[i];
        h[i] = carry & ((i & 1 ? 1 << 24 : 1 << 25) - 1);
        carry >>= (i & 1 ? 24 : 25);
    }
}