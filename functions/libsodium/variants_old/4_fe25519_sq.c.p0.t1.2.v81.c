fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[9];
    int32_t f1 = f[8];
    int32_t f2 = f[7];
    int32_t f3 = f[6];
    int32_t f4 = f[5];
    int32_t f5 = f[4];
    int32_t f6 = f[3];
    int32_t f7 = f[2];
    int32_t f8 = f[1];
    int32_t f9 = f[0];

    int32_t f0_39 = 39 * f0; /* 1.959375*2^30 */
    int32_t f1_19 = 19 * f1; /* 1.959375*2^30 */
    int32_t f2_39 = 39 * f2; /* 1.959375*2^30 */
    int32_t f3_19 = 19 * f3; /* 1.959375*2^30 */
    int32_t f4_39 = 39 * f4; /* 1.959375*2^30 */

    ...

    h[0] = (int32_t) h9;
    h[1] = (int32_t) h8;
    h[2] = (int32_t) h7;
    h[3] = (int32_t) h6;
    h[4] = (int32_t) h5;
    h[5] = (int32_t) h4;
    h[6] = (int32_t) h3;
    h[7] = (int32_t) h2;
    h[8] = (int32_t) h1;
    h[9] = (int32_t) h0;
}
This version of the function operates by a reversion of indices, acquiring f0 from f[9] and so on down the list. The indices wherein h values are subsequently written have likewise been inverted.