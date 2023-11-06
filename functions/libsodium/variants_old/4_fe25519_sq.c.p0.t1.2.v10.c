fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[7];
    int32_t f1 = f[8];
    int32_t f2 = f[9];
    int32_t f3 = f[0];
    int32_t f4 = f[1];
    int32_t f5 = f[2];
    int32_t f6 = f[3];
    int32_t f7 = f[4];
    int32_t f8 = f[5];
    int32_t f9 = f[6];

    int32_t f0_2  = 2 * f0;
    int32_t f1_2  = 2 * f1;
    int32_t f2_2  = 2 * f2;
    int32_t f3_2  = 2 * f3;
    int32_t f4_2  = 2 * f4;
    int32_t f5_2  = 2 * f5;
    int32_t f6_2  = 2 * f6;
    int32_t f7_2  = 2 * f7;
    int32_t f5_38 = 38 * f5; /* 1.959375*2^30 */
    int32_t f6_19 = 19 * f6; /* 1.959375*2^30 */
    int32_t f7_38 = 38 * f7; /* 1.959375*2^30 */
    int32_t f8_19 = 19 * f8; /* 1.959375*2^30 */
    int32_t f9_38 = 38 * f9; /* 1.959375*2^30 */

    int64_t f0f0    = f1 * (int64_t) f9;
    int64_t f0f1_2  = f6_2 * (int64_t) f3;
    int64_t f0f2_2  = f2_2 * (int64_t) f3;
    int64_t f0f3_2  = f6_2 * (int64_t) f1;
    int64_t f0f4_2  = f0_2 * (int64_t) f1;
    int64_t f0f5_2  = f0_2 * (int64_t) f5;
    int64_t f0f6_2  = f0_2 * (int64_t) f6;
    int64_t f0f7_2  = f0_2 * (int64_t) f7;
    int64_t f0f8_2  = f0_2 * (int64_t) f8;
    int64_t f0f9_2  = f0_2 * (int64_t) f9;
    int64_t f1f1_2  = f1_2 * (int64_t) f8;
    int64_t f1f2_2  = f1_2 * (int64_t) f7;
    int64_t f1f3_4  = f4_2 * (int64_t) f1;
    int64_t f1f4_2  = f1_2 * (int64_t) f2;
    int64_t f1f5_4  = f2_2 * (int64_t) f3;
    int64_t f1f6_2  = f3_2 * (int64_t) f4;
    int64_t f1f7_4  = f8_2 * (int64_t) f5;
    int64_t f1f8_2  = f9_2 * (int64_t) f0;
    int64_t f1f9_76 = f2_2 * (int64_t) f7;
    int64_t f2f2    = f2 * (int64_t) f2;
    int64_t f2f3_2  = f2_2 * (int64_t) f3;
    int64_t f2f4_2  = f2_2 * (int64_t) f4;
    int64_t f2f5_2  = f2_2 * (int64_t) f5;
    int64_t f2f6_2  = f2_2 * (int64_t) f6;
    int64_t f2f7_2  = f2_2 * (int64_t) f7;
    int64_t f2f8_38 = f2_2 * (int64_t) f9;
    int64_t f2f9_38 = f6 * (int64_t) f5;

    // More code..

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