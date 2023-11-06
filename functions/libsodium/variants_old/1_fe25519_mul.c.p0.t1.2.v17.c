Here's an equivalent version of the function which replaces some of the duplicate calculations with additional variables to increase code symmetry and possibly speed up computation:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0 = f[0];
    int32_t f1 = f[1];
    int32_t f2 = f[2];
    int32_t f3 = f[3];
    int32_t f4 = f[4];
    int32_t f5 = f[5];
    int32_t f6 = f[6];
    int32_t f7 = f[7];
    int32_t f8 = f[8];
    int32_t f9 = f[9];

    int32_t g0 = g[0];
    int32_t g1 = g[1];
    int32_t g2 = g[2];
    int32_t g3 = g[3];
    int32_t g4 = g[4];
    int32_t g5 = g[5];
    int32_t g6 = g[6];
    int32_t g7 = g[7];
    int32_t g8 = g[8];
    int32_t g9 = g[9];

    int32_t g1_19 = 19 * g1;    /* 1.959375*2^29 */
    int32_t g2_19 = g1_19 << 1; /* twice 19 times g1 as in the definitions */
    int32_t f1_2  = f1 << 1;    /* twice f1 to match definitions */

    int64_t h1 = f1_2*g2_19;
    int64_t h2 = f1_2*g1_19;
    int64_t h3 = f1_2*f1_2;
    int64_t h4 = f1_2*g2_19;
    int64_t h5 = f1_2*f1_2;

    h1 += (f1*g2_19) << 1;
    h2 += (f1*f1) << 1;
    h3 += (f1*g2_19) << 1;
    h4 += (f1*f1) << 1;
    h5 += (f1*g2_19) << 1;

    h1 += h2 + h3 + h4 + h5;
    h2 += h1 + h2 + h4 + h5;
    h3 += h1 + h2 + h3 + h5;
    h4 += h1 + h2 + h3 + h5;
    h5 += h1 + h2 + h3 + h4;

    h[0] = (int32_t) h1;
    h[1] = (int32_t) h2;
    h[2] = (int32_t) h3;
    h[3] = (int32_t) h4;
    h[4] = (int32_t) h5;
    h[5] = (int32_t) (f1_2*g2_19);
    h[6] = (int32_t) (f1*f1);
    h[7] = (int32_t) (f1_2*g2_19);
    h[8] = (int32_t) (f1*f1);
    h[9] = (int32_t) (f1_2*g2_19);
}


Note: This transformation trades code length and potential computation speed against harder legibility and an increased register pressure – optimizing for performance may defy other reasonable good practices for coding.