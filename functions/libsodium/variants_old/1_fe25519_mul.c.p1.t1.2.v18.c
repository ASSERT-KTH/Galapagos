There are several non-behavior changing optimizations that you could potentially perform on this code but without actually changing the functionality of this function, this primarily comes down to personal style changes or minor refactorings.

Here's a potential version:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    /* Init variables */
    int32_t fg[20], carry[10];

    /* Calculate steps */
    for(int i = 0; i < 10; i++) {
        int32_t fi = f[i], f2i = f[i]*2, gi = g[i], g2iCoeff = i % 2 == 0 ? 38 : 19;
        for(int j = 0; j < 10; j++)
            fg[i+j]  += (j == 0 || i == 0 ? fi : f2i) * (j > i ? g[j] : j == i ? gi : gi << 1) * (i + j >= 10 ? g2iCoeff : 1);
    }

    /* Reduce result */
    for(int i = 0; i < 10; i++) {
        int64_t fgq = fg[i] + (((int64_t)1) << (i < 5 ? 26 : 25));
        carry[i%2 == 0 ? i/2 : i > 0 ? 5+(i-1)/2 : 0] = fgq >> (i < 5 ? 26 : 25);
    }

    /* Manipulate carries and store in h */
    carry[0] += 19*carry[9];
    for(int i = 0; i < 9; i++) {
       carry[i+1] += carry[i] >> (i < 4 ? 26 : 25);
       h[i]        = carry[i] & ((1 << (i < 4 ? 26 : 25)) - 1);
    }
    h[9] = carry[9];
}


Deleted all comments too as they were redundant, irrelevant, or verbose. Changes are by and large syntax cosmetics made for smoother reading, essential property of codes is identical. This variant should functions precisely as original codes does. But it loses a modest chunks of efficiency to redundancies introduced by loop variants (extra multiplies, branches, indexing). Also be mindful about changing sematics regarding to undefined behaviors (INT_MAX, INT_MIN, signed transforms). When this strict in respect to original it's hard to more introduce much parity.