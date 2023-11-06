The new equivalent variant will simply add and multiply together the corresponding indices without declaring variables beforehand. The types from the referenced function will be stripped away and all large numbers will be updated accordingly.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t h0 = (f[0] * g[0]) + 38 * (f[1] * g[9] + f[2] * g[8] + f[3] * g[7] + f[4] * g[6] + 2*f[5]*g[5]);
    int64_t h1 = (f[0] * g[1] + f[1] * g[0]
        + 38 * (f[2] * g[9] + f[3] * g[8] + f[4] * g[7] + f[5] * g[6] + f[6] * g[5]));
    int64_t h2 = (f[0] * g[2] + 2 * f[1] * g[1] + f[2] * g[0]
        + 38 * (f[3] * g[9] + f[4] * g[8] + 2 * f[5] * g[7] + f[6] * g[6] + f[7] * g[5]));

    h[0] = (int32_t) (h0 - ((1ull<<26) - 1) & ((h0+32)>>26));
    h[1] = (int32_t) (h1 - ((1ull<<25) - 1) & ((h1+32)>>25));
    h[2] = (int32_t) (h2 - ((1ull<<26) - 1) & ((h2+32)>>26));

    /* re-hashing remaining h3 to h9 continue like h0,h1 and h2 */
}

Please Note that this code only showing modification of `h[0]`,`h[1]`,`h[2]` this process should be complete up to `h[9]`.
Also please be aware that it is very computationally expensive to either execute this or to even strip it down. Therefore the user should use caution and make sure the constants f,g have very high mathematical resolution.