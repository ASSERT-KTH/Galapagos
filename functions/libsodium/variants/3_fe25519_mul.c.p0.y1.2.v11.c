void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fi[10], gi[10];
    uint64_t tmp[10], t;
    int i;

    for (i = 0; i < 10; i++) {
        fi[i] = f[i];
        gi[i] = g[i];
    }

    for (i = 0; i < 10; i++) {
        int j;
        for (j = 0; j <= i; j++)
            tmp[         i-j]  =          fi[j] * gi[i-j];
        for   (; j < 10; j++)
            tmp[9 + j-i] +=   19 * (fi[j] * gi[   i-j]); // equivalence of 38 * fi[2j] * gi[9]
    }                                                     // and fi[2j] * gi[9]*19

    for (i = 0; i < 10; i++) 
        h[i] = tmp[i];

    /* reduce coefficients */
    for (i = 0; i < 9; i++) {
        t = (h[i] + ((int64_t)1<<25)) >> 26;
        h[i+1] += t;
        h[i] -= t<<26;
    }

    t = (h[9] + ((int64_t)1<<24)) >> 25;
    h[0] += 19*t;
    h[9] -= t<<25;

    for (i = 0; i < 10; i++) 
        h[i] = h[i];

    /* now h0...h8 are nonnegative but h9 can be too large */
    t = (h[0] + ((int64_t)1<<25)) >> 26;
    h[0] -= t<<26;
    h[1] += t;
    /* h0...h9 are now in the correct range */
}