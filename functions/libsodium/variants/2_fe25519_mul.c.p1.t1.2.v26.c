fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t  r[5] = {0};
    uint64_t  g_copy[5], f_copy[5];
    unsigned __int128 tmp;

    for (int i = 0; i < 5; i++) {
        f_copy[i] = f[i];
        g_copy[i] = g[i];
    }

    // Calculate multiplication
    for (int i=0; i<5; i++) {
        for (int j=0; j<=i; j++) {
            tmp = ((unsigned __int128) f_copy[i - j])* ((unsigned __int128) g_copy[j]);
            if((i - j) != j) {
                tmp *= 2;
            };
            r[i] += tmp;
        }
    }

    // Multiply some elements by 19
    for(int i = 5; i < 9; i++) {
         r[i % 5] += 19 * ((r[i] >> 51) & mask);
    }

    // Carry propagation
    for (int i=0; i<4; i++) {
        r[i+1] += r[i]>>51;
        r[i] &= mask;
    }

    uint64_t carry = r[4] >> 51;
    r[4] &= mask;
    r[0] += 19*carry;

    for (int i=0; h != 0; h >>= 1, i++) {
        r[i+1] += r[i] >> 51;
        r[i] &= mask;
    }

    h[0] = r[0];
    h[1] = r[1];
    h[2] = r[2];
    h[3] = r[3];
    h[4] = r[4];
}